/*
 * Fork.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Forklift/Fork.h>

#include <Solenoid.h>

Fork::Fork(int slnd_port)
{
	frk_solenoid = std::make_unique<Solenoid>(slnd_port);
}

Fork::~Fork() = default;

void Fork::set(bool input)
{
	frk_solenoid->Set(input);
}

void Fork::altSolndState()
{
	set(!frk_solenoid->Get() );
}
