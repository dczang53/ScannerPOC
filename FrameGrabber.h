#pragma once

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <Share.h>
#include <ctime>
#include <errno.h>
#include "SphinxLib.h"

using namespace System;
using namespace System::Drawing;

extern Int32 FRAME_HORIZ;
extern Int32 FRAME_VERT;

ref class FrameGrabber
{
public:
	FrameGrabber();
	~FrameGrabber();
	Bitmap^ getFrame();		//WILL CACHE A COPY OF THE CURRENT FRAME IN A FILE NAMED "buffer.bmp"
private:
};
