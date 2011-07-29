#include "timeReference.h"

TimeReference* TimeReference::m_pInstance = 0; 

TimeReference::TimeReference(void)
{
	fps=1;
	firstFrame=-1;
	lastFrame=-1;
}

TimeReference::~TimeReference(void)
{

}

TimeReference* TimeReference::Instance()
{
	if (!m_pInstance)
		m_pInstance = new TimeReference;
	return m_pInstance;
}

int TimeReference::framesPerSecond()
{
	return fps;
}

Time TimeReference::frameToTime(int frameNumber)
{
	return frameNumber/fps;
}

int TimeReference::timeToFrame(Time time)
{
	return fps*time;
}

int TimeReference::getFirstFrame()
{
	return firstFrame;
}
int TimeReference::getLastFrame()
{
	return lastFrame;
}
int TimeReference::frameExist(int frameNumber)
{
	return (frameNumber>=firstFrame) && (frameNumber<=lastFrame);
}

void TimeReference::setFps(int newFps)
{
	if(fps>0)	fps=newFps;
}

void TimeReference::registerFrame(int frameNumber)
{
	if(frameNumber < 0)	return;
	if(firstFrame==-1 || lastFrame==-1)
	{
		firstFrame=frameNumber;
		lastFrame=frameNumber;
		return;
	}
	if(frameNumber < firstFrame)	firstFrame=frameNumber;
	if(frameNumber > lastFrame)		lastFrame=frameNumber;
}

