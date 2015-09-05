/*
 * Fork.h
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#ifndef SRC_FORKLIFT_FORK_H_
#define SRC_FORKLIFT_FORK_H_

#include <memory>

class Solenoid;

class Fork
{
private:
	std::unique_ptr<Solenoid> frk_solenoid;
	void set(bool input);
public:
	Fork(int slnd_port);
	~Fork();
	void altSolndState();
};

#endif /* SRC_FORKLIFT_FORK_H_ */
