/*
 * Forklift.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Forklift/Forklift.h>

#include "Configs/Configs.h"

#include <iostream>

Forklift::Forklift(int porta, PORT_TYPES PTa, int portb, PORT_TYPES PTb, int channela, SWITCHPOS posa, int channelb, SWITCHPOS posb) :
	Fork((PTa == PORT_TYPES::SOLENOID) ? porta : portb),
	Elevator(((PTa == PORT_TYPES::MOTOR) ? porta : portb), channela, posa, channelb, posb)
{

}
