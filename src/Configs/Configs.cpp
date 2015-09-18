/*
 * Configs.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: norayu
 */

#include <Configs/Configs.h>

//in millisec
const double Configs::ACCEL_TIME = 250.0;

//in feet
const double Configs::ZERO_THROTTLE_THRESHOLD = 0.016;

//it's a scalar
const double Configs::THROTTLE_MULTIPLIER = 0.5;

//in ft
const double Configs::MAX_TURN_RADIUS = 2.0;

//in ft
const double Configs::ROBOT_WIDTH = 2.0;

//CONTROLLER PORTS
const double Configs::DRIVE_CONTROLLER_PORT = 1;
const double Configs::ELEVATOR_CONTROLLER_PORT = 2;

//scalar
const double Configs::ELEVATOR_MULTIPLIER = 0.2;

const int Configs::FORK_TOGGLE_BIND = 2;

const int Configs::SWITCH_SENSITIVITY = 4;

const int Configs::PANIC_BIND = 11;
