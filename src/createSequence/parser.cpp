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
//		line.substr(0,line.find("\t")); FIXME
		std::stringstream strStream(line.substr(6,2));
		int frameNumber;
		strStream >> frameNumber;
		frameNumber *= FRAME_PER_SEC;
		
		frameData* f = new frameData();
		(*data)[frameNumber] = f;
		
	}
	std::cout << data->size() << "  " << data->capacity() << std::endl;
	
	
	return data;
}

int Parser::parseTime(std::string timeString)
{
	return 0;
}
