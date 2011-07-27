#include "parser.h"

#include <iostream>
#include <fstream>
#include <sstream>

#define FRAME_PER_SEC	1	//TODO : use the class instead

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
	std::string line;
	std::ifstream infile (inputFile.c_str(), std::ifstream::in);
	while (getline(infile, line, '\n'))
	{
//FRAME_PER_SEC * 
//		std::string frameNumber = line.substr(0,line.find("\t"));
		std::stringstream strStream(line.substr(6,2));
		int frameNumber;
		
		strStream >> frameNumber;
		frameNumber *= FRAME_PER_SEC;

		std::cout << frameNumber << std::endl;
		frameData* f = new frameData();
//		data.insert(frameNumber, f); TODO HERE I WAS
		
	}
	
	return data;
}

int Parser::parseTime(std::string timeString)
{
	return 0;
}
