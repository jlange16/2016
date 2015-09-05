/*
 * LimitSwitch.h
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#ifndef SRC_SWITCH_LIMITSWITCH_H_
#define SRC_SWITCH_LIMITSWITCH_H_

#include <memory>

class DigitalInput;
class Counter;

class LimitSwitch
{
private:
	std::unique_ptr<DigitalInput> dig_inpt;
	std::unique_ptr<Counter> counter;
	int curr_count = 0;
	int prev_count = 0;
public:
	LimitSwitch(int channel);
	~LimitSwitch();
	void update();
	bool isSwitched();
	void reset();
};

#endif /* SRC_SWITCH_LIMITSWITCH_H_ */
