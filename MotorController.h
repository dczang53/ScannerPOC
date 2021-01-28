#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::IO::Ports;

ref class MotorController
{
public:
	MotorController();
	~MotorController();

	Void setReadTimeout(Int32 ms);	//default is 500ms
	Void setWriteTimeout(Int32 ms);	//default is 500ms
	Boolean isOpen();
	Boolean initPort(String^ port, String^ baudRate);
	Boolean moveMotor(Int32 motor1, Int32 motor2);
	Void abortMotion();

private:
	IContainer^ m_components;
	SerialPort^ m_serialPort;
};

