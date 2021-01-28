#include "MotorController.h"

MotorController::MotorController()
{
	m_components = (gcnew System::ComponentModel::Container());
	m_serialPort = (gcnew System::IO::Ports::SerialPort(this->m_components));
}

MotorController::~MotorController()
{
	if (m_components)
		delete m_components;
}

Void MotorController::setReadTimeout(Int32 ms)
{
	m_serialPort->ReadTimeout = ms;
}

Void MotorController::setWriteTimeout(Int32 ms)
{
	m_serialPort->WriteTimeout = ms;
}

Boolean MotorController::isOpen()
{
	return (m_serialPort->IsOpen);
}

Boolean MotorController::initPort(String^ port, String^ baudRate)
{
	try
	{	
		m_serialPort->Close();
		m_serialPort->PortName = port;
		m_serialPort->BaudRate = Int32::Parse(baudRate);
		m_serialPort->Open();
		return true;
	}
	catch (UnauthorizedAccessException^)
	{
		return false;
	}
}

Boolean MotorController::moveMotor(Int32 motor1, Int32 motor2)
{
	if (!m_serialPort->IsOpen)
		return false;
	if ((motor1 == 0) && (motor2 == 0))
		return true;
	String^ buffer = "!1";
	if (motor1 != 0)
	{
		buffer += "m1";
		if(motor1 < 0)
		{
			buffer += "r";
			motor1 *= -1;
		}
		else
			buffer += "f";
		buffer += motor1.ToString();
	}
	if (motor2 != 0)
	{
		buffer += "m2";
		if(motor2 < 0)
		{
			buffer += "r";
			motor2 *= -1;
		}
		else
			buffer += "f";
		buffer += motor2.ToString();
	}
	buffer += "n";
	m_serialPort->WriteLine(buffer);
	try
	{
		Byte response = m_serialPort->ReadByte();
		if (response != 'a')
			return false;
		response = m_serialPort->ReadByte();
		if (response != 'o')
			return false;
		return true;
	}
	catch (TimeoutException^)
	{
		return false;
	}
}

Void MotorController::abortMotion()
{
	if (!m_serialPort->IsOpen)
		return;
	//Int32 tries = 0;
	while (true)
	{
		try
		{
			Byte response = '1';	//dummy byte
			while (response != '0')
			{
				m_serialPort->WriteLine("!1a");
				m_serialPort->ReadByte();
				m_serialPort->WriteLine("!1rs");
				response = m_serialPort->ReadByte();
			}
			return;
		}
		catch (TimeoutException ^) //not really needed, but added just in case; can remove if you want
		{
			//tries++;
			//if (tries > 4)
			//	return;
			continue;
		}
	}
	
	
}