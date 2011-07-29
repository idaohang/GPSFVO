#include "gpsData.h"

#include "timeReference.h"

#include <iostream>

GpsData::GpsData(void)
{

}

GpsData::~GpsData(void)
{

}

std::string GpsData::getKeyAtFrame(int frameNumber, std::string key,
							 		TimedFrameData * former,
							 		TimedFrameData * later ) const
{
	FrameData * fData;
	FrameData::const_iterator it;
	//Discard bad frame numbers
	if( ! TimeReference::Instance()->frameExist(frameNumber) )	return "";
	if( key == "") return "";

	//1. Try the exact frame value
	fData = (*this)[frameNumber];
	if(fData)
	{
		//Look the key if available
		it = fData->find(key);
		if(it != fData->end())
		{
			return it->second;
		}
	}
	
	//2. Try to find former or later values if aked for iterator
	if(! former || ! later) return "";
	int firstFrame = TimeReference::Instance()->getFirstFrame();
	int lastFrame = TimeReference::Instance()->getLastFrame();

	//Look for a former value
	for(int f=frameNumber; f>=firstFrame; f--)
	{
		fData = (*this)[f];
		if(fData)
		{
			//Look the key if available
			it = fData->find(key);
			if(it != fData->end())	//Found
			{
				former->first=f;
				former->second=it->second;
				break;
			}
		}
	}

	//Look for a later value
	for(int f=frameNumber; f<=lastFrame; f++)
	{
		fData = (*this)[f];
		if(fData)
		{
			//Look the key if available
			it = fData->find(key);
			if(it != fData->end())	//Found
			{
				later->first=f;
				later->second=it->second;
				break;
			}
		}
	}

	return "";
}

