/*
 * UserController.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef USERCONTROLLER_H_
#define USERCONTROLLER_H_

#include <memory>

enum F310_AXIS
{
	LEFT_X_AXIS,
	LEFT_Y_AXIS,
	LEFT_TRIGGER,
	RIGHT_TRIGGER,
	RIGHT_X_AXIS,
	RIGHT_Y_AXIS
};


class Joystick;

class UserController {
private:
	std::shared_ptr<Joystick> p_joystick;
public:
	UserController(int port);
	double getLeftXAxis();
	double getLeftYAxis();
	double getRightXAxis();
	double getRightYAxis();

};

#endif /* USERCONTROLLER_H_ */
