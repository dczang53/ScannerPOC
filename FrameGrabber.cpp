#include "FrameGrabber.h"

BYTE WINAPI error_callback_func(BYTE cam_nr, char* error_str);
unsigned short save_bmp(char* fname, DWORD w, DWORD h, BYTE bpp, BYTE* ppixel);

FrameGrabber::FrameGrabber()
{
	WORD error;
	DISCOVERY dis;
	CONNECTION con;
	BYTE camera = 1;		// default camera to choose from discovery

	//discover Gige cameras
	error = GEVDiscovery(&dis, NULL, 200, 0);
	if ((error) || (dis.Count == 0))	// if no cameras found camera 1 chosen automatically
		return;

	// set CONNECTION parameter for GEVInit function
	con.AdapterIP = dis.param[camera - 1].AdapterIP;              // network adapter ip address
	con.AdapterMask = dis.param[camera - 1].AdapterMask;          // network  adapter mask
	con.IP_CANCam = dis.param[camera - 1].IP;                     // device ip address
	con.PortCtrl = 49149;                                       // control port, set 0 to port than automatic port is use
	con.PortData = 49150;                                       // stream port, set 0 to port than automatic port is use
	strcpy(con.adapter_name, dis.param[camera - 1].adapter_name);  // name of network adapter

	// init GigE device
	error = GEVInit(camera, &con, error_callback_func, 0, EXCLUSIVE_ACCESS);
	if (error)
		return;

	// init xml parser
	error = GEVInitXml(camera);
	if (error)
		return;

	// open stream channel
	error = GEVOpenStreamChannel(camera, con.AdapterIP, con.PortData, 0);
	if (error)
		return;

	// custom settings
	error = GEVSetFeatureEnumeration(camera, "PixelFormat", "RGB8Packed", 10);
	if (error)
		return;
	error = GEVSetFeatureEnumeration(camera, "CameraType", "NTSC", 4);
	if (error)
		return;
	error = GEVSetFeatureEnumeration(camera, "ScanType", "FFP", 3);
	if (error)
		return;

	// disable packet resend
	error = GEVSetPacketResend(camera, 0);
	if (error)
		return;

	// set stream channel packet delay to 500 (default 0)
	error = GEVSetFeatureInteger(camera, "GevSCPD", 500);
	if (error)
		return;
}

FrameGrabber::~FrameGrabber() {}

Bitmap^ FrameGrabber::getFrame()
{
	WORD error;
	BYTE camera = 1;		// default camera to choose from discovery
	BOOL valid = true;

	Color black = Color::FromArgb(255, 0, 0, 0);
	Bitmap^ failFrame = gcnew Bitmap(FRAME_HORIZ, FRAME_VERT);
	for (Int32 x = 0; x < FRAME_HORIZ; x++)
		for (Int32 y = 0; y < FRAME_VERT; y++)
			failFrame->SetPixel(x, y, black);

	// start acquisition
	IMAGE_HEADER img_header;
	INT64 dw64;
	DWORD width, height, img_size;
	BYTE bpp;
	DWORD pixelFormat;
	BYTE* ppixel[4];
	BYTE index = 0;

	ppixel[0] = NULL;

	// get current image width from the device
	error = GEVGetFeatureInteger(camera, "Width", &dw64);
	if (error)
	{
		valid = false;
		goto END;
	}
	width = (DWORD)dw64;

	// get current image height from the device
	error = GEVGetFeatureInteger(camera, "Height", &dw64);
	if (error)
	{
		valid = false;
		goto END;
	}
	height = (DWORD)dw64;

	// get current image pixel format from the device
	error = GEVGetFeatureInteger(camera, "PixelFormat", &dw64);
	if (error)
	{
		valid = false;
		goto END;
	}
	pixelFormat = (DWORD)dw64;
	bpp = (BYTE)((GVSP_PIX_EFFECTIVE_PIXEL_SIZE_MASK & pixelFormat) >> (GVSP_PIX_EFFECTIVE_PIXEL_SIZE_SHIFT + 3)) * 8;

	// get current image size (payload size) from the device
	error = GEVGetFeatureInteger(camera, "PayloadSize", &dw64);
	if (error)
	{
		valid = false;
		goto END;
	}
	img_size = (int)dw64;

	// allocate memory for the image, ringbuffer is handled directly in library
	ppixel[0] = (BYTE*)malloc(img_size);               //used by function GEVGetImageBuffer

  // start acquisition
	error = GEVAcquisitionStart(camera, 1);
	if (error)
	{
		valid = false;
		goto END;
	}

	Sleep(500);		//Need a delay otherwise frame capture fail rate increases (MODIFY AS YOU SEE FIT)

	error = GEVGetImageBuffer(camera, &img_header, ppixel[0]);
	if ((error) && (error != GEV_STATUS_GRAB_ERROR))
	{
		valid = false;
		goto END;
	}

	// stop acquisition
	error = GEVAcquisitionStop(camera);
	if (error)
	{
		valid = false;
		goto END;
	}

	std::time_t now = std::time(nullptr);
	char timestamp[50];
	strftime(timestamp, 50, "%Y%m%d_%H%M%S", localtime(&now));
	char bufferFile[200] = "\0";
	strcat(bufferFile, "BufferedFrames/Frame-");
	strcat(bufferFile, timestamp);
	strcat(bufferFile, ".bmp");

	// save last image as bitmap to disk
	error = save_bmp(bufferFile, width, height, bpp, ppixel[index]);
	if (error)
	{
		valid = false;
		goto END;
	}

END:
	// free image memory
	if (ppixel[0])
		free(ppixel[0]);
	if (valid)
	{
		String^ bufferName = gcnew String(bufferFile);
		Bitmap^ frame = gcnew Bitmap(bufferName);
		frame = gcnew Bitmap(frame, FRAME_HORIZ, FRAME_VERT);
		return frame;
	}
	else
		return failFrame;
}

BYTE WINAPI error_callback_func(BYTE cam_nr, char* error_str)	//literally just a stand-in function for GEVInit
{
	return(0);
}

unsigned short save_bmp(char* fname, DWORD w, DWORD h, BYTE bpp, BYTE* ppixel)
{
	BITMAPFILEHEADER bmpfilehdr;
	BITMAPINFOHEADER bmpinfohdr;
	int i, bpp_h, h_off;
	int size, width, height;
	FILE* hfile;
	BYTE* phelp, lbpp;
	RGBQUAD pal1;

	if ((hfile = _fsopen(fname, "w+b", _SH_DENYNO)) == NULL)
		return(1);

	if (bpp == 16)
		lbpp = 8;
	else
		lbpp = bpp;

	bpp_h = lbpp / 8;
	if (lbpp == 8)
		h_off = 1024;
	else
		h_off = 0;

	width = (int)w;
	height = (int)h;
	size = (width * bpp_h) * height;

	// build bmp headers
	bmpfilehdr.bfType = 0x4D42;
	bmpfilehdr.bfSize = size + sizeof(BITMAPINFOHEADER) + (sizeof(BITMAPFILEHEADER)) + h_off;
	bmpfilehdr.bfReserved1 = 0;
	bmpfilehdr.bfReserved2 = 0;
	bmpfilehdr.bfOffBits = sizeof(BITMAPINFOHEADER) + (sizeof(BITMAPFILEHEADER)) + h_off;

	bmpinfohdr.biSize = sizeof(BITMAPINFOHEADER);
	bmpinfohdr.biWidth = width;
	bmpinfohdr.biHeight = height;
	bmpinfohdr.biPlanes = 1;
	bmpinfohdr.biBitCount = lbpp;
	bmpinfohdr.biCompression = 0;
	bmpinfohdr.biSizeImage = size;
	bmpinfohdr.biXPelsPerMeter = 0;
	bmpinfohdr.biYPelsPerMeter = 0;

	if (bpp == 8)
	{
		bmpinfohdr.biClrUsed = 256;
		bmpinfohdr.biClrImportant = 256;
	}
	else
	{
		bmpinfohdr.biClrUsed = 0;
		bmpinfohdr.biClrImportant = 0;
	}

	if (fwrite((unsigned char*)&bmpfilehdr, sizeof(BITMAPFILEHEADER), 1, hfile) == 0)
		return(2);

	if (fwrite((unsigned char*)&bmpinfohdr, sizeof(BITMAPINFOHEADER), 1, hfile) == 0)
		return(2);

	if (lbpp == 8)
	{
		// Palette init.
		for (i = 0; i < 256; i++)
		{
			pal1.rgbRed = (unsigned char)i;
			pal1.rgbGreen = (unsigned char)i;
			pal1.rgbBlue = (unsigned char)i;
			pal1.rgbReserved = 0;
			if (fwrite(&pal1, sizeof(RGBQUAD), 1, hfile) == 0)
				return(2);
		}
	}

	for (i = height - 1; i >= 0; i--)
	{
		phelp = ppixel + ((width * bpp_h) * i);
		if (fwrite(phelp, (width * bpp_h), 1, hfile) == 0)
			return(2);
	}

	fclose(hfile);

	return(0);
}