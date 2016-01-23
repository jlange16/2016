/*
 * MotorInterface.h
 *
 *  Created on: Jan 22, 2016
 *      Author: norayu
 */

#ifndef SRC_MOTORS_MOTORINTERFACE_H_
#define SRC_MOTORS_MOTORINTERFACE_H_

class MotorInterface
{
public:
	virtual ~MotorInterface() = 0;
	virtual void setSpeed(double speed) = 0;
	virtual void kill() = 0;
};

#endif /* SRC_MOTORS_MOTORINTERFACE_H_ */
