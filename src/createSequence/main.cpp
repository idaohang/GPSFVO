#include <iostream>

#include "parser.h"
#include "timeReference.h"

int main (int argc, char * argv[])
{

	TimeReference::Instance()->setFps(10);

	Parser p(argv[1]);

	p.parse();
	
	return 0;
}
