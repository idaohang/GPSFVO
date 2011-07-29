#include "parser.h"

#include <iostream>
#include <fstream>
#include <sstream>

#define FRAME_PER_SEC	25	//TODO : use the class instead

Parser::Parser(std::string fileName)
{
	inputFile = fileName;
}

Parser::~Parser(void)
{

}

void Parser::configure()
{
	
}

GpsData* Parser::parse()
{
	GpsData * data = new GpsData();
	data->reserve(45*FRAME_PER_SEC); //TODO....
		
	std::string line;
	std::ifstream infile (inputFile.c_str(), std::ifstream::in);
	while (getline(infile, line, '\n'))
	{
		int frameNumber = parseTime(line.substr(0,line.find("\t")));
		
		int start = line.find("\t", line.find("\t")+1);
		int end = line.find("\t", start+1);
		std::string speed = parseSpeed(line.substr(start+1,end-start-1));

		start = line.find("\t", end);
		end = line.find(" ", start+1);
		std::string angle = line.substr(start+1,end-start-1);

		
		frameData* f = new frameData();
		f->insert(frameData::value_type("speed", speed));
		f->insert(frameData::value_type("angle", angle));
		(*data)[frameNumber] = f;
		
	}
	std::cout << data->size() << "  " << data->capacity() << std::endl;
	
	
	return data;
}

int Parser::parseTime(std::string timeString)
{
	std::stringstream strStream(timeString.substr(6,2));
	int time;
	strStream >> time;
	time *= FRAME_PER_SEC;
	return time;
}

std::string Parser::parseSpeed(std::string speedString)
{
	std::string returned;
	speedString[2]='.';
/*	std::stringstream strStream(speedString.substr(0,5));
	float speed=0.0;
	strStream >> speed;*/

	return speedString.substr(0,5);
}


