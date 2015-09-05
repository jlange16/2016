#include "WPILib.h"
#include <memory>

#include "DriveControllers/TeleopDriveTrainController.h"
#include "User Controls/UserController.h"
#include "DriveTrain/DriveBase.h"
#include "Configs/Configs.h"
#include "Forklift/TeleopForkliftController.h"
#include "Forklift/Forklift.h"

#include <Joystick.h>

#include <stdexcept>

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;


	//user controls
	std::unique_ptr<UserController> F310;
	std::unique_ptr<UserController> JStick;

	//teleop controllers
	std::unique_ptr<TeleopDriveTrainController> TDTC;
	//not team fortress classic!
	std::unique_ptr<TeleopForkliftController> TFC;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();

		std::cout << "Build Num: " << __DATE__ << "    " << __TIME__ << std::endl;

		//takes in motor ports
		//may need to be changed later
		//for now, values placeholder
		DriveBase::getInstance(
				0, RIGHT_FOR,
				1, RIGHT_BCK,
				2, LEFT_FOR,
				3, LEFT_BCK);

		//takes in motor type and ports
		//place holders for now
		Forklift::getInstance(
				4, PORT_TYPES::MOTOR,
				1, PORT_TYPES::SOLENOID,
				4, SWITCHPOS::TOP,
				5, SWITCHPOS::BOTTOM);


		F310 = std::make_unique<UserController>(Configs::DRIVE_CONTROLLER_PORT);

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

		TDTC = std::make_unique<TeleopDriveTrainController>(F310.get(), &DriveBase::getInstance(), DriveType::TANK);
		TFC = std::make_unique<TeleopForkliftController>(Forklift::getInstance(), JStick.get() );
	}

	void TeleopPeriodic()
	{
		try
		{
			if(F310->getRawJoystick()->GetRawButton(Configs::PANIC_BIND) )
			{
				throw std::runtime_error("PANIC! ABORT ABORT ABORT");
			}
			TDTC->update();
			TFC->update();
		}
		catch(std::runtime_error& e)
		{
			//sets speed to 0
			DriveBase::getInstance().setAll(0.0);
			Forklift::getInstance().setEleSpeed(0.0);

			//kills motors
			DriveBase::getInstance().kill();
			Forklift::getInstance().kill();
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
