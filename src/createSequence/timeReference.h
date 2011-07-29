#ifndef TIME_REFERENCE_H__
#define TIME_REFERENCE_H__

typedef unsigned int Time;

//Singleton
class TimeReference
{
public:

	static TimeReference* Instance();

	~TimeReference(void);
	
	int framesPerSecond();
	Time frameToTime(int frameNumber);
	int timeToFrame(Time time);
	int getFirstFrame();
	int getLastFrame();
	int frameExist(int frameNumber);
	
	void setFps(int newFps);
	void registerFrame(int frameNumber);

protected:
	int fps;
	int firstFrame;
	int lastFrame;

private:
	TimeReference(void);
	TimeReference(TimeReference const&){};
//	TimeReference& operator=(TimeReference const&){};	Throwing a warning....
	static TimeReference* m_pInstance;
};


#endif  // _TIME_REFERENCE_H__
