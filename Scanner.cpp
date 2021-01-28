#include "Scanner.h"
#include "frmSandTimages.h"

//using namespace System::Threading;

Scanner::Scanner(SandTimages::frmSandTimages^ form)
{
	m_form = form;
	m_motorController = (gcnew MotorController());
	m_frameGrabber = (gcnew FrameGrabber());
}

Scanner::~Scanner()
{

}










//SET SCANNER VARIABLES
Void Scanner::lockScan()
{
	m_semaphore = false;
}

Void Scanner::unlockScan()
{
	m_semaphore = true;
}

Void Scanner::getTopXY(Int32 &x, Int32 &y)
{
	x = Convert::ToInt32(m_XTop);
	y = Convert::ToInt32(m_YTop);
}

Void Scanner::getRightXY(Int32 &x, Int32 &y)
{
	x = Convert::ToInt32(m_XRight);
	y = Convert::ToInt32(m_YRight);
}

Void Scanner::getBottomXY(Int32 &x, Int32 &y)
{
	x = Convert::ToInt32(m_XBottom);
	y = Convert::ToInt32(m_YBottom);
}

Void Scanner::getLeftXY(Int32 &x, Int32 &y)
{
	x = Convert::ToInt32(m_XLeft);
	y = Convert::ToInt32(m_YLeft);
}

Void Scanner::getCenterXY(Int32 &x, Int32 &y)
{
	x = Convert::ToInt32(m_XCenter);
	y = Convert::ToInt32(m_YCenter);
}

Boolean Scanner::setTopXY(Int32 x, Int32 y)
{
	if ((x < 0) || (y < 0) || (x >= FRAME_HORIZ) || (y >= FRAME_VERT))
		return false;
	m_XTop = x;
	m_YTop = y;
	return true;
}

Boolean Scanner::setRightXY(Int32 x, Int32 y)
{
	if ((x < 0) || (y < 0) || (x >= FRAME_HORIZ) || (y >= FRAME_VERT))
		return false;
	m_XRight = x;
	m_YRight = y;
	return true;
}

Boolean Scanner::setBottomXY(Int32 x, Int32 y)
{
	if ((x < 0) || (y < 0) || (x >= FRAME_HORIZ) || (y >= FRAME_VERT))
		return false;
	m_XBottom = x;
	m_YBottom = y;
	return true;
}

Boolean Scanner::setLeftXY(Int32 x, Int32 y)
{
	if ((x < 0) || (y < 0) || (x >= FRAME_HORIZ) || (y >= FRAME_VERT))
		return false;
	m_XLeft = x;
	m_YLeft = y;
	return true;
}

Boolean Scanner::setCenterXY(Int32 x, Int32 y)
{
	if ((x < 0) || (y < 0) || (x >= FRAME_HORIZ) || (y >= FRAME_VERT))
		return false;
	m_XCenter = x;
	m_YCenter = y;
	return true;
}

Void Scanner::setImageSize(Int32 horiz, Int32 vert)
{
	m_imageHoriz = horiz;
	m_imageVert = vert;
}

Void Scanner::setTopDiag(Int32 x, Int32 y)
{
	m_XTopDiag = m_XTop + (0.707 * x);
	m_YTopDiag = m_YTop + ((1 - 0.707) * y);
}

Void Scanner::setDT(Int32 dT)
{
	m_dT = dT;
}

Void Scanner::setDS(Int32 dS)
{
	m_dS = dS;
}










//FRAME OPERATION IMPLEMENTATIONS
Void Scanner::acquireDisplayFrame()
{
	m_displayFrame = m_frameGrabber->getFrame();
}

Void Scanner::acquireFrameCenter()
{
	if (m_displayFrame == nullptr)
		return;
	Int32 Xoffset = (m_XCenter - m_dT), Yoffset = (m_YCenter - m_dT);
	Int32 centerLen = (2 * m_dT) + 1;
	Color black = Color::FromArgb(255, 0, 0, 0);
	m_frameCenter = gcnew Bitmap(centerLen, centerLen);
	for (Int32 x = 0; x < centerLen; x++)
		for (Int32 y = 0; y < centerLen; y++)
		{
			Int32 Xpos = (Xoffset + x), Ypos = (Yoffset + y);
			if ((Xpos < 0) || (Xpos >= FRAME_HORIZ) || (Ypos < 0) || (Ypos >= FRAME_VERT))
				m_frameCenter->SetPixel(x, y, black);
			else
				m_frameCenter->SetPixel(x, y, m_displayFrame->GetPixel(Xpos, Ypos));
		}
}

Bitmap^ Scanner::getDisplayFrame()
{
	return m_displayFrame;
}

Bitmap^ Scanner::getFrameCenter()
{
	return m_frameCenter;
}

Int32 Scanner::calcTBoxAverage()
{
	Int32 total = 0;
	Int32 limit = (m_dT <= D_SIDE)? m_dT : D_SIDE;
	Int32 xMin = (m_XCenter - limit), xMax = (m_XCenter + limit);
	Int32 yMin = (m_YCenter - limit), yMax = (m_YCenter + limit);
	for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			total += (((((m_displayFrame->GetPixel(x, y)).ToArgb()) << 8) >> 24) & 0x000000FF);
	return (total / ((2 * limit + 1) * (2 * limit + 1)));
}

Int32 Scanner::calcStBoxAverage()
{
	Int32 total = 0;
	Int32 limit = (m_dS <= D_SIDE) ? m_dS : D_SIDE;
	Int32 xMin = (m_XTopDiag - limit), xMax = (m_XTopDiag + limit);
	Int32 yMin = (m_YTopDiag - limit), yMax = (m_YTopDiag + limit);
	for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			total += (((((m_displayFrame->GetPixel(x, y)).ToArgb()) << 8) >> 24) & 0x000000FF);
	return (total / ((2 * limit + 1) * (2 * limit + 1)));
}

Int32 Scanner::calcSrBoxAverage()
{
	Int32 total = 0;
	Int32 limit = (m_dS <= D_SIDE) ? m_dS : D_SIDE;
	Int32 xMin = (m_XRight - limit), xMax = (m_XRight + limit);
	Int32 yMin = (m_YRight - limit), yMax = (m_YRight + limit);
	for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			total += (((((m_displayFrame->GetPixel(x, y)).ToArgb()) << 8) >> 24) & 0x000000FF);
	return (total / ((2 * limit + 1) * (2 * limit + 1)));
}

Int32 Scanner::calcSbBoxAverage()
{
	Int32 total = 0;
	Int32 limit = (m_dS <= D_SIDE) ? m_dS : D_SIDE;
	Int32 xMin = (m_XBottom - limit), xMax = (m_XBottom + limit);
	Int32 yMin = (m_YBottom - limit), yMax = (m_YBottom + limit);
	for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			total += (((((m_displayFrame->GetPixel(x, y)).ToArgb()) << 8) >> 24) & 0x000000FF);
	return (total / ((2 * limit + 1) * (2 * limit + 1)));
}

Int32 Scanner::calcSlBoxAverage()
{
	Int32 total = 0;
	Int32 limit = (m_dS <= D_SIDE) ? m_dS : D_SIDE;
	Int32 xMin = (m_XLeft - limit), xMax = (m_XLeft + limit);
	Int32 yMin = (m_YLeft - limit), yMax = (m_YLeft + limit);
	for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			total += (((((m_displayFrame->GetPixel(x, y)).ToArgb()) << 8) >> 24) & 0x000000FF);
	return (total / ((2 * limit + 1) * (2 * limit + 1)));
}

Void Scanner::writeSquareT()
{
	if (m_displayFrame == nullptr)
		return;
	Int32 xMin = (m_XCenter - m_dT - 1), xMax = (m_XCenter + m_dT + 1);
	Int32 yMin = (m_YCenter - m_dT - 1), yMax = (m_YCenter + m_dT + 1);
	Color blue = Color::FromArgb(255, 0, 255, 255);
	if ((yMin >= 0) && (yMin < FRAME_VERT))
		for (Int32 x = ((xMin >= 0)? xMin : 0), X = ((xMax < FRAME_HORIZ)? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMin, blue);
	if ((yMax >= 0) && (yMax < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMax, blue);
	if ((xMin >= 0) && (xMin < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMin, y, blue);
	if ((xMax >= 0) && (xMax < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMax, y, blue);
}

Void Scanner::writeAllSquareS()
{
	if (m_displayFrame == nullptr)
		return;
	Int32 xMin = (m_XTopDiag - m_dS - 1), xMax = (m_XTopDiag + m_dS + 1);
	Int32 yMin = (m_YTopDiag - m_dS - 1), yMax = (m_YTopDiag + m_dS + 1);
	Color green = Color::FromArgb(255, 0, 255, 0);
	if ((yMin >= 0) && (yMin < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMin, green);
	if ((yMax >= 0) && (yMax < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMax, green);
	if ((xMin >= 0) && (xMin < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMin, y, green);
	if ((xMax >= 0) && (xMax < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMax, y, green);

	xMin = (m_XRight - m_dS - 1), xMax = (m_XRight + m_dS + 1);
	yMin = (m_YRight - m_dS - 1), yMax = (m_YRight + m_dS + 1);
	if ((yMin >= 0) && (yMin < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMin, green);
	if ((yMax >= 0) && (yMax < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMax, green);
	if ((xMin >= 0) && (xMin < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMin, y, green);
	if ((xMax >= 0) && (xMax < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMax, y, green);
	
	xMin = (m_XBottom - m_dS - 1), xMax = (m_XBottom + m_dS + 1);
	yMin = (m_YBottom - m_dS - 1), yMax = (m_YBottom + m_dS + 1);
	if ((yMin >= 0) && (yMin < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMin, green);
	if ((yMax >= 0) && (yMax < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMax, green);
	if ((xMin >= 0) && (xMin < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMin, y, green);
	if ((xMax >= 0) && (xMax < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMax, y, green);
	
	xMin = (m_XLeft - m_dS - 1), xMax = (m_XLeft + m_dS + 1);
	yMin = (m_YLeft - m_dS - 1), yMax = (m_YLeft + m_dS + 1);
	if ((yMin >= 0) && (yMin < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMin, green);
	if ((yMax >= 0) && (yMax < FRAME_VERT))
		for (Int32 x = ((xMin >= 0) ? xMin : 0), X = ((xMax < FRAME_HORIZ) ? xMax : (FRAME_HORIZ - 1)); x <= X; x++)
			m_displayFrame->SetPixel(x, yMax, green);
	if ((xMin >= 0) && (xMin < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMin, y, green);
	if ((xMax >= 0) && (xMax < FRAME_HORIZ))
		for (Int32 y = ((yMin >= 0) ? yMin : 0), Y = ((yMax < FRAME_VERT) ? yMax : (FRAME_VERT - 1)); y <= Y; y++)
			m_displayFrame->SetPixel(xMax, y, green);
}










//SCANNER OPERATION IMPLEMENTATIONS
Void Scanner::acquireImageTandS()
{
	Color gray = Color::FromArgb(255, 128, 128, 128);
	m_imageT = gcnew Bitmap(m_imageHoriz, m_imageVert);
	m_imageS = gcnew Bitmap(m_imageHoriz, m_imageVert);
	for(int i = 0; i < m_imageHoriz; i++)
		for (int j = 0; j < m_imageVert; j++)
		{
			m_imageT->SetPixel(i, j, gray);
			m_imageS->SetPixel(i, j, gray);
		}
	Int32 inc = 1;
	Int32 x = 0, y = 0;
	while (x < m_imageHoriz)
	{
		while ((y >= 0) && (y < m_imageVert))
		{
			if (m_semaphore)
				return;
			acquireDisplayFrame();
			acquireFrameCenter();
			writeSquareT();
			writeAllSquareS();
			formLoadFrames();
			//Tasks::Task::Delay(50)->Wait();
			Int32 averageT = calcTBoxAverage();
			m_imageT->SetPixel(x, y, Color::FromArgb(255, averageT, averageT, averageT));
			Int32 averageSt = calcStBoxAverage();
			Int32 averageSr = calcSrBoxAverage();
			Int32 averageSb = calcSbBoxAverage();
			Int32 averageSl = calcSlBoxAverage();
			Int32 averageS = (averageSt + averageSr + averageSb + averageSl) / 4;
			m_imageS->SetPixel(x, y, Color::FromArgb(255, averageS, averageS, averageS));
			formLoadBoxAverages(averageSt, averageSr, averageSb, averageSl, averageT);
			formLoadImages();
			//motorMoveMotor(0, inc);
			y += inc;
		}
		inc *= -1;
		//motorMoveMotor(1, inc);
		y += inc;
		//motorMoveMotor(1, 0);
		x++;
	}
	m_imageT->Save("ImageT.bmp");
	m_imageS->Save("ImageS.bmp");
	formLoadImages();
}

Bitmap^ Scanner::getImageT()
{
	return m_imageT;
}

Bitmap^ Scanner::getImageS()
{
	return m_imageS;
}

//Bitmap^ Scanner::getImageCore() {}










//PARENT FORM FUNCTION TO REFRESH IMAGES IMPLEMENTATION
Void Scanner::formLoadFrames()
{
	m_form->loadDisplayFrame();
	m_form->loadFrameCenter();
}

Void Scanner::formLoadImages()
{
	m_form->loadImageT();
	m_form->loadImageS();
}

Void Scanner::formLoadRGB(Int32 R)
{
	m_form->loadRGB(R);
}

Void Scanner::formLoadBoxAverages(Int32 St, Int32 Sr, Int32 Sb, Int32 Sl, Int32 T)
{
	m_form->loadBoxAverages(St, Sr, Sb, Sl, T);
}








//MOTORCONTROLLER CONTROL IMPLEMENTATIONS
Void Scanner::motorSetReadTimeout(Int32 ms)
{
	m_motorController->setReadTimeout(ms);
}

Void Scanner::motorSetWriteTimeout(Int32 ms)
{
	m_motorController->setWriteTimeout(ms);
}

Boolean Scanner::motorIsOpen()
{
	return m_motorController->isOpen();
}

Boolean Scanner::motorInitPort(String^ port, String^ baudRate)
{
	return m_motorController->initPort(port, baudRate);
}

Boolean Scanner::motorMoveMotor(Int32 motor1, Int32 motor2)
{
	return m_motorController->moveMotor(motor1, motor2);
}

Void Scanner::motorAbortMotion()
{
	m_motorController->abortMotion();
}

/*
TODO:
-acquireDisplayFrame (to be modified later when framegrabber is available)
*/












































/*
void Scanner::CalcTandS(int RedPic, int x, int y, int dT, int dS, int Ring, int& T, int& S, int& Core)
{

	Dim I, J As Integer
	Dim SImin, SIMAX, SJmin, SJMAX As Integer
	Dim TImin, TIMAX, TJmin, TJMAX As Integer
	Dim Red, Green, Blue As Integer
	Dim FileName As String

	Dim Row As Long
	Dim TotalLight, CoreSum, TSum, SSum As Long
	Dim NumberOfPointsT, NumberOfPointsS, NumberOfPointsCore As Long
	Dim RowLong As Long

	Row = TotalLight = Core = T = S = 0
	CoreSum = TSum = SSum = 0

	SImin = x - dS      'dS defines the distance to compute scattering
	SIMAX = x + dS      'usually dS is something from 20 min to 50 MAX
	SJmin = y - dS
	SJMAX = y + dS
	NumberOfPointsCore = (2 * Ring + 1) * (2 * Ring + 1)
	NumberOfPointsS = (2 * dS + 1) * (2 * dS + 1) - NumberOfPointsCore

	For J = SJmin To SJMAX    'Remember that I chopped at 478 because the
						'computer did not like to go further
		For I = SImin To SIMAX
			Row = Row + RedPic(I, J) '+ GreenPic(I, J) + BluePic(I, J)
		Next I
		RowLong = Row
		TotalLight = TotalLight + RowLong
		Row = 0
		Next J
	'Upon leaving this loop TotalLight contains the integrated
	'illumination on the scattered area as defined by dS

	CoreSum = 0       'Initialize value to subtract from TotalLight
				'to get the total scattered radiation
				'Note that the boundaries here (SJmin, etc.) must surround the
				'boundaries below(TJmin, etc.).  This is so because in the
				'process of canculating the total scattered light intensity (Sij)
				'one must eliminate ALL the central core plus a little more
				'around this central core just to be sure not to include any
				'transmitted light (Tij), while for the calculation of T(ij)
				'it is better to stop perhaps even a little short of the true
				'bright central spot, that is, a smaller area than the area
				'used for S(ij)

	SImin = x - Ring    'Ring is an exclusion ring around T
	SIMAX = x + Ring
	SJmin = y - Ring
	SJMAX = y + Ring
	For J = SJmin To SJMAX
	   For I = SImin To SIMAX
		  CoreSum = CoreSum + RedPic(I, J)
	   Next I
	Next J
	SSum = TotalLight - CoreSum   'This is the total scattered radiation
	Core = CoreSum / NumberOfPointsCore
	S = SSum / NumberOfPointsS

	TSum = 0       'Initialize value of total transmitted radiation

	TImin = x - dT
	TIMAX = x + dT
	TJmin = y - dT
	TJMAX = y + dT
	NumberOfPointsT = (2 * dT + 1) * (2 * dT + 1)

	For J = TJmin To TJMAX
	   For I = TImin To TIMAX
		  TSum = TSum + RedPic(I, J)
	   Next I
	Next J
	T = TSum / NumberOfPointsT

}
*/

/*
void Scanner::PutTickMarkOnImage(int& EC24Image1)
{
	'   This sub will not be used after the overhaul of April 20, 2004
	'   It will be substituted by subPutSquaresAndTickMarksOnImage

	Dim xLong, yLong As Long

	For yLong = 1 To 25    'Put 4 lines up as picture markers
		xLong = 50
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 100
		EC24Image1.SetPixel xLong, yLong, 0, 255, 255
		xLong = 150
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 200
		EC24Image1.SetPixel xLong, yLong, 0, 255, 255
		xLong = 250
		EC24Image1.SetPixel xLong, yLong, 0, 255, 0
		xLong = 300
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 350
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 400
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 450
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 500
		EC24Image1.SetPixel xLong, yLong, 0, 255, 0
		xLong = 550
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 600
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
	Next yLong
}
*/

/*
void Scanner::PutTickMarkOnImage1(int& EC24Image1)
{
	Dim xLong, yLong As Long

	For yLong = 1 To 25    'Put 4 lines up as picture markers
		xLong = 50
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 100
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 150
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 200
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 250
		EC24Image1.SetPixel xLong, yLong, 0, 255, 0
		xLong = 300
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 350
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 400
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 450
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 500
		EC24Image1.SetPixel xLong, yLong, 0, 255, 0
		xLong = 550
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
		xLong = 600
		EC24Image1.SetPixel xLong, yLong, 0, 0, 255
	Next yLong
}
*/