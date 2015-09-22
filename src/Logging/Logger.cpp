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

void Logger::clearLine()
{
	//goes up a line
	std::cout << "\x1b[A";

	//goes to beginning of line
	std::cout << "/r";

	//clears it
	for(int i = 0; i <= CHAR_CLEAR; i++)
	{
		std::cout << " ";
	}
}

void Logger::updateLogs()
{
	for(int i = 0; i <= Logger::queue.size(); i++)
	{
		Logger::clearLine();
	}

	//prints queue
	for(auto& it : Logger::queue)
	{
		std::cout << it << std::endl;
	}

	//clears queue
	Logger::queue.clear();
}
