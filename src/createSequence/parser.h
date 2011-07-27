#ifndef PARSER_H__
#define PARSER_H__

#include <string>

#include "gpsData.h"

class Parser
{
public:

	Parser(std::string fileName);

	~Parser(void);

	//Configure input file format
	void configure();
	
	GpsData* parse();

protected:

	std::string inputFile;

private:
};


#endif  // _PARSER_H__
