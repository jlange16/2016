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
	std::unique_ptr<Joystick> p_joystick;
public:
	UserController(int port);
	~UserController();
	double getLeftXAxis() const;
	double getLeftYAxis() const;
	double getRightXAxis() const;
	double getRightYAxis() const;
	double getJoystickYAxis() const;
	Joystick* getRawJoystick() const;

};

#endif /* USERCONTROLLER_H_ */
