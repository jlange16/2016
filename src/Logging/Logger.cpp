/*
 * Logger.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: norayu
 */

#include <Logging/Logger.h>

#include <iostream>

const int CHAR_CLEAR = 500;

std::vector<std::string> Logger::queue;

void Logger::addToQueue(std::string add)
{
	Logger::queue.push_back(add);
}

void Logger::print(std::string str)
{
	//moves to beginning of line
	std::cout << "/r";

	//clears line
	for(int i = 0; i <= CHAR_CLEAR; i++)
	{
		std::cout << " ";
	}

	//prints input string
	std::cout << str << std::endl;
}

void Logger::updateLogs()
{
	//prints queue
	for(auto& it : Logger::queue)
	{
		print(it);
	}

	//clears queue
	Logger::queue.clear();
}
