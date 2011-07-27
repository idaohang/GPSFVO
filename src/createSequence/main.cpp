#include <iostream>

#include "parser.h"

int main (int argc, char * argv[])
{

	Parser p(argv[1]);

	p.parse();
	
	return 0;
}
