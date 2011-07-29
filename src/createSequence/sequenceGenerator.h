#ifndef SEQUENCE_GENERATOR_H__
#define SEQUENCE_GENERATOR_H__

#include <string>

class SequenceGenerator
{
public:

   SequenceGenerator(void);

   ~SequenceGenerator(void);

	void generate(int startFrame, int endFrame, std::string filenamePrefix);
	void configure(void); 	//TODO Some kid of dictionnary

protected:
private:
};


#endif  // _SEQUENCE_GENERATOR_H__
