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
	Forklift* fl;


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
		db = DriveBase::getInstance(
				0, LEFT_FOR,
				1, LEFT_BCK,
				2, RIGHT_FOR,
				3, RIGHT_BCK);

		//takes in motor type and ports
		//place holders for now
		fl = Forklift::getInstance(
				4, PORT_TYPES::MOTOR,
				1, PORT_TYPES::SOLENOID,
				4, SWITCHPOS::TOP,
				5, SWITCHPOS::BOTTOM);


		F310 = std::make_unique<UserController>(Configs::DRIVE_CONTROLLER_PORT);
		JStick = std::make_unique<UserController>(Configs::ELEVATOR_CONTROLLER_PORT);

		assert(F310.get() );
		assert(JStick.get() );

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
		TFC = std::make_unique<TeleopForkliftController>(fl, JStick.get() );
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
			TFC->update();
		}
		catch(KillRobot& e)
		{
			//sets speed to 0
			db->setAll(0.0);
			fl->setEleSpeed(0.0);

			//kills motors
			db->kill();
			fl->kill();

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
