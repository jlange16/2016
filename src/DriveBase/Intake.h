/*
 * Intake.h
 *
 *  Created on: Feb 22, 2016
 *      Author: user
 */

#ifndef SRC_DRIVEBASE_INTAKE_H_
#define SRC_DRIVEBASE_INTAKE_H_

#include <memory>

class Motor;

class Intake
{
private:
	std::unique_ptr<Motor> _motor;
public:
	Intake(unsigned int port);
	~Intake();
	void setSpeed(double speed);
};

#endif /* SRC_DRIVEBASE_INTAKE_H_ */
