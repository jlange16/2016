/*
 * TeleopDriveTrainController.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef TELEOPDRIVETRAINCONTROLLER_H_
#define TELEOPDRIVETRAINCONTROLLER_H_

#include <memory>
#include "DriveTrain/DriveBase.h"

class UserController;
class DriveBase;

enum class DriveType
{
	TANK
};

class TeleopDriveTrainController {
private:
	UserController* p_user_controller;
	DriveBase* p_drive_base;
	DriveType current_type;

	void setStraight(double speed);
	void turnInPlace(double speed);
	void setTurn(double throttle, double turn);
	double findThrottle(double throttle);
	double findTurn(double throttle);

public:
	TeleopDriveTrainController(UserController* const controller, DriveBase* const drivebase, DriveType drivetype);
	~TeleopDriveTrainController();
	void update();
};

#endif /* TELEOPDRIVETRAINCONTROLLER_H_ */
