#ifndef GPS_DATA_H__
#define GPS_DATA_H__

#include <string>
#include <map>
#include <vector>

typedef std::map<std::string, std::string> frameData;

class GpsData : public std::vector<frameData*>
{
public:

	GpsData(void);

	~GpsData(void);


protected:
	
private:
};


#endif  // _GPS_DATA_H__
