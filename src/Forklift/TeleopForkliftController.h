/*
 * TeleopForkliftController.h
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#ifndef SRC_FORKLIFT_TELEOPFORKLIFTCONTROLLER_H_
#define SRC_FORKLIFT_TELEOPFORKLIFTCONTROLLER_H_

class Forklift;
class UserController;

class TeleopForkliftController
{
private:
	Forklift* forklift;
	UserController* controller;

public:
	TeleopForkliftController(Forklift* fl, UserController* uc);
	void update();

};

#endif /* SRC_FORKLIFT_TELEOPFORKLIFTCONTROLLER_H_ */
