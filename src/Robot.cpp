#include "WPILib.h"
#include <memory>

#include "DriveControllers/TeleopDriveTrainController.h"
#include "User Controls/UserController.h"
#include "DriveTrain/DriveBase.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	std::shared_ptr<int> test;
	std::shared_ptr<UserController> F310;
	std::shared_ptr<TeleopDriveTrainController> TDTC;

	void RobotInit()
	{
		lw = LiveWindow::GetInstance();
		//takes in motor ports
		DriveBase::getInstance(0,1,2,3);

		const int controller_port = 0;

		F310.reset(new UserController(controller_port) );

	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

		TDTC.reset(new TeleopDriveTrainController(F310.get(), &DriveBase::getInstance(), TANK) );
	}

	void TeleopPeriodic()
	{
		TDTC->update();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
