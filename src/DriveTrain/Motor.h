/*
 * Motor.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <memory>

class TalonSRX;

class Motor {
private:
	std::unique_ptr<TalonSRX> talon;
public:
	Motor(int channel);
	~Motor();
	void setSpeed(float speed);
	void disable();
};

#endif /* MOTOR_H_ */
