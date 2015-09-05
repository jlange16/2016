/*
 * Forklift.h
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#ifndef SRC_FORKLIFT_FORKLIFT_H_
#define SRC_FORKLIFT_FORKLIFT_H_

#include "Forklift/Fork.h"
#include "Forklift/Elevator.h"

#include <memory>
#include <cassert>

enum class PORT_TYPES
{
	MOTOR,
	SOLENOID
};

enum class SWITCHPOS;

class Forklift : public Fork, public Elevator
{
private:
public:

	Forklift(int porta, PORT_TYPES PTa, int portb, PORT_TYPES PTb, int channela, SWITCHPOS posa, int channelb, SWITCHPOS posb);
	~Forklift();

	template<class... T>
	static Forklift& getInstance(T... types)
	{
		static Forklift* fl = new Forklift(types...);
		assert(fl);
		return *fl;
	};
};

#endif /* SRC_FORKLIFT_FORKLIFT_H_ */
