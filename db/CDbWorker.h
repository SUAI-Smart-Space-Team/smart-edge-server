#include <string>



#pragma once


#pragma warning(disable : 4996)  

using namespace std;

class CDbWorker
{
public:
	virtual string init(string path) = 0;
	virtual ~CDbWorker() = default;
	virtual string getPumpColor() = 0;
	virtual string getCoolerColor() = 0;
	virtual string getPumpSpeed() = 0;
	virtual string getCoolerSpeed() = 0;

	virtual string getRAM(string idDevice) = 0;
	virtual string getCPU(string idDevice) = 0;
	virtual string getTemp(string idDevice) = 0;
	virtual string Close() = 0;

};

