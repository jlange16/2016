#include "WPILib.h"
#include <memory>

#include "DriveControllers/TeleopDriveTrainController.h"
#include "User Controls/UserController.h"
#include "DriveTrain/DriveBase.h"
#include "Configs/Configs.h"

#include <Joystick.h>

#include <stdexcept>

class KillRobot : public std::runtime_error
{
public:
	KillRobot() : std::runtime_error("ROBOT HAS BEEN ABORTED"){};
};

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;


	//robo parts
	DriveBase* db;


	//user controls
	std::unique_ptr<UserController> F310;

	//teleop controllers
	std::unique_ptr<TeleopDriveTrainController> TDTC;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();

		std::cout << "Build Num: " << __DATE__ << "    " << __TIME__ << std::endl;

		//takes in motor ports
		//may need to be changed later
		//for now, values placeholder
		db = DriveBase::getInstance(
				0, LEFT,
				1, LEFT,
				2, LEFT,
				3, RIGHT,
				4, RIGHT,
				5, RIGHT);

		/*
		 * 0-2 LEFT
		 * 3-5 RIGHT
		 */

		F310 = std::make_unique<UserController>(Configs::DRIVE_CONTROLLER_PORT);

		assert(F310.get() );

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

		TDTC = std::make_unique<TeleopDriveTrainController>(F310.get(), db, DriveType::TANK);
	}

	void TeleopPeriodic()
	{
		try
		{
			if(F310->getRawJoystick()->GetRawButton(Configs::PANIC_BIND) )
			{
				throw KillRobot();
			}
			TDTC->update();
		}
		catch(KillRobot& e)
		{
			//sets speed to 0
			db->setAll(0.0);

			//kills motors
			db->kill();

			//throws exception
			throw e;
		}
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
