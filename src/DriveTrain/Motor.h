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
	std::shared_ptr<TalonSRX> talon;
public:
	Motor(int channel);
	void setSpeed(float speed);
};

#endif /* MOTOR_H_ */
