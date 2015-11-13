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
#include <iostream>

enum Side
{
	RIGHT,
	LEFT,
	NONE
};

class DriveBase {
private:
	std::map<int, std::unique_ptr<Motor> > all_motors;

	DriveBase& addMotor()
	{
		return *this;
	}

	template<typename... T>
	DriveBase& addMotor(T... types)
	{
		throw std::runtime_error("MISSING PORT OR TYPE");
	};

	template<typename... T>
	DriveBase& addMotor(int port, Side wt, T... types)
	{
		std::cout << "Added motor" << wt << "@ port" << port << std::endl;
		all_motors.emplace(wt, std::make_unique<Motor>(port) );
		addMotor(types...);

		return *this;
	};
	template<typename... T>
	DriveBase(T... types)
	{
		addMotor(types...);
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
