#ifndef GPS_DATA_H__
#define GPS_DATA_H__

#include <string>
#include <map>
#include <vector>

typedef std::map<std::string, std::string> FrameData;
typedef std::pair<int, std::string> TimedFrameData;

class GpsData : public std::vector<FrameData*>
{
public:

	GpsData(void);

	~GpsData(void);
	
	//Return the value if available or an empty string.
	//If former and later values had been found, they are stored in the
	//optionnal parameter former and later with their frameNumber.
	std::string getKeyAtFrame(int frameNumber, std::string key, 
						 		TimedFrameData * former=0,
						 		TimedFrameData * later=0 ) const;


protected:
	
private:
};


#endif  // _GPS_DATA_H__
