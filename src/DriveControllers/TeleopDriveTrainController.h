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

class TeleopDriveTrainController {
private:
	std::shared_ptr<UserController> p_user_controller;
	std::shared_ptr<DriveBase> p_drive_base;
	DriveType current_type;

	void setStraight(double speed);
	void turnInPlace(double speed);
	void setTurn(double l_speed, double r_speed);
	double findWheelSpeeds(double throttle, double turn);

public:
	TeleopDriveTrainController(UserController* const controller, DriveBase* const drivebase, DriveType drivetype);
	void update();
};

#endif /* TELEOPDRIVETRAINCONTROLLER_H_ */
