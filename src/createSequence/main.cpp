#include <iostream>

#include "parser.h"
#include "timeReference.h"

int main (int argc, char * argv[])
{
	TimedFrameData f1,f2;
	std::string s;

	TimeReference::Instance()->setFps(25);

	Parser p(argv[1]);

	GpsData * g = p.parse();
	
	
	for(int f=TimeReference::Instance()->getFirstFrame();
				f<=TimeReference::Instance()->getLastFrame(); f++)
	{
		s = g->getKeyAtFrame(f,"angle",&f1,&f2);
		std::cout << "Angle at " << f << " is ";

		if (s.size()>0)
		{
			std::cout << s;
		}
		else
		{
			std::cout << f1.second << "(" << f1.first << ") - ";
			std::cout << f2.second << "(" << f2.first << ")";
		}
	
		std::cout << std::endl;

	}
	
	
	return 0;
}
