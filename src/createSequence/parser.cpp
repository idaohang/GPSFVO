#include "parser.h"

#include <iostream>
#include <fstream>

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
	std::string line;
	std::ifstream infile (inputFile.c_str(), std::ifstream::in);
	while (getline(infile, line, '\n'))
	{
		std::cout << line << std::endl;
	}
	
	return 0;
}

