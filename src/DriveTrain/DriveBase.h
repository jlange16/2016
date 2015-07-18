/*
 * DriveBase.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef DRIVEBASE_H_
#define DRIVEBASE_H_

#include <memory>
#include <map>

enum DriveType
{
	TANK,
	MECANUM,
	SLIDE
};

enum Side
{
	RIGHT,
	LEFT
};

class Motor;

class DriveBase {
private:
	DriveBase(int motor_a, int motor_b, int motor_c, int motor_d);
	std::map<int, std::shared_ptr<Motor> > all_motors;
	std::map<std::shared_ptr<Motor>, Side> motors_side;

public:
	static DriveBase& getInstance(int motor_a = -1, int motor_b = -1, int motor_c = -1, int motor_d = -1);
	void setAll(double speed);
	void setIndividual(int port, double speed);
	void setDouble(Side side, double speed);
};

#endif /* DRIVEBASE_H_ */
