/*
 * DriveBase.h
 *
 *  Created on: Jul 18, 2015
 *      Author: nlele
 */

#ifndef DRIVEBASE_H_
#define DRIVEBASE_H_

#include "DriveTrain/Motor.h"

#include <memory>
#include <map>
#include <stdexcept>
#include <cassert>

enum WheelTypes
{
	RIGHT_FOR,
	RIGHT_BCK,
	LEFT_FOR,
	LEFT_BCK,
	OTHER
};

enum Side
{
	RIGHT,
	LEFT,
	NONE
};

class DriveBase {
private:
	std::map<int, std::unique_ptr<Motor> > all_motors;

	void addMotor()
	{
	}

	template<typename... T>
	void addMotor(T... types)
	{
		throw std::runtime_error("MISSING PORT OR TYPE");
	};

	template<typename... T>
	void addMotor(int port, WheelTypes wt, T... types)
	{
		all_motors[wt] = std::make_unique<Motor>(port);
	};
	template<typename... T>
	DriveBase(T... types)
	{

	};

public:
	template<typename... T>
	static DriveBase* getInstance(T... types)
	{
		static DriveBase* db = new DriveBase(types...);
		assert(db);
		return db;
	};
	~DriveBase();
	void kill();
	void setAll(double speed);
	void setIndividual(int port, double speed);
	void setSide(Side side, double speed);
};

#endif /* DRIVEBASE_H_ */
