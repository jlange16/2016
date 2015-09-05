/*
 * Elevator.h
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#ifndef SRC_FORKLIFT_ELEVATOR_H_
#define SRC_FORKLIFT_ELEVATOR_H_

#include <memory>
#include <map>

class Motor;
class LimitSwitch;

enum class SWITCHPOS
{
	TOP,
	BOTTOM
};

class Elevator
{
private:
	std::map<SWITCHPOS, std::unique_ptr<LimitSwitch>> boundary;
	std::unique_ptr<Motor> ele_motor;

	bool is_above = false;
	bool is_below = false;
	bool top_in_prog = false;
	bool bttm_in_prg = false;
public:
	Elevator(int port, int channela, SWITCHPOS posa, int channelb, SWITCHPOS posb);
	~Elevator();
	void checkSafety();
	void setEleSpeed(double speed);
	void kill();
	void reset();
};

#endif /* SRC_FORKLIFT_ELEVATOR_H_ */
