/*
 * Logger.cpp
 *
 *  Created on: Sep 18, 2015
 *      Author: norayu
 */

#include <Logging/Logger.h>

#include <iostream>
#include <fstream>

const std::string LOG_PATH = "/home/lvuser/logs/log.txt";

std::vector<std::string> Logger::queue;

std::ofstream file;

Logger::Logger()
{
	//appends instead of overwrites
	std::cout << "Since we don't have boost, we cannot create directories!"
			"Make sure a directory doesn't need to be made @ "
			<< LOG_PATH << std::endl;

	file.open(LOG_PATH, std::ios_base::app);
}

void Logger::addToQueue(std::string add)
{
	Logger::queue.push_back(add);
}

void Logger::updateLogs()
{
	//prints queue
	for(auto& it : Logger::queue)
	{
		file << it << std::endl;
	}

	//clears queue
	Logger::queue.clear();
}
