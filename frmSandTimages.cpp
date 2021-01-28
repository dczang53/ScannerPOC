#include "frmSandTimages.h"

using namespace System;
using namespace System::Windows::Forms;

//DEFINE ALL GLOBALS HERE
Int32 SCROLLBARMAXOFFSET = 9;			//maximum value for scrollbar is set this many units above intended max, to allow for the scrollbar to reach intended max (ie max set to 109 when actual max in app is 100)
Int32 FRAME_HORIZ = 640;
Int32 FRAME_VERT = 480;
Int32 SQR_SIDE = 21;					//size of individual square frame from FrameGrabber (MUST BE ODD)
Int32 D_SIDE = ((SQR_SIDE - 1) / 2);

[STAThreadAttribute]

int main(array <String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SandTimages::frmSandTimages form;
	Application::Run(% form);
	return 0;
}