/*
 * DriveBase.h
 *
 *  Created on: Jan 29, 2016
 *      Author: norayu
 */

#ifndef SRC_DRIVEBASE_DRIVEBASE_H_
#define SRC_DRIVEBASE_DRIVEBASE_H_

#include "Motors/MotorInterface.h"

#include <memory>
#include <unordered_map>
#include <stdexcept>

enum class Side
{
	Right,
	Left,
	None
};

class DriveBaseError : public std::runtime_error
{
public:
	DriveBaseError(std::string what);
};

class DriveBase {
private:
	std::unordered_map<MotorInterface*, Side> _motors;

	void addMotors(){};

	template <class... T>
	void addMotors(MotorInterface* mw, Side side, T... args)
	{
		_motors[mw] = side;
		addMotors(args...);
	}

public:

	template <class... Mtrs>
	DriveBase(Mtrs... args)
	{
		addMotors(args...);
	}

	void setSide(double speed, Side side);
	void setAll(double speed);
	void setIndividual(double speed, MotorInterface* mw);
};

#endif /* SRC_DRIVEBASE_DRIVEBASE_H_ */
