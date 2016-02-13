/*
 * AutoDriveController.h
 *
 *  Created on: Feb 13, 2016
 *      Author: user
 */

#ifndef SRC_DRIVECONTROLLERS_AUTODRIVECONTROLLER_H_
#define SRC_DRIVECONTROLLERS_AUTODRIVECONTROLLER_H_

class DriveBase;

class AutoDriveController
{
private:
	DriveBase* _db;
	//the bottom class is for binds
	class Robot;
public:
	AutoDriveController(DriveBase* db);
	void run();
};

#endif /* SRC_DRIVECONTROLLERS_AUTODRIVECONTROLLER_H_ */
