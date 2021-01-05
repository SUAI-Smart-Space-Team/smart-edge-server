#pragma once
#include <map>
#include "sqlite3.h"
#include "CDbWorker.h"
#include "../config.h"
#include "../Tools.h"
class CSQLiteDbWorker :
	public CDbWorker
{
public:
	CSQLiteDbWorker();
	string init(string path);
	~CSQLiteDbWorker();
	string getPumpColor();
	string getCoolerColor();
	string getPumpSpeed();
	string getCoolerSpeed();

	string getRAM(string idDevice);
	string getCPU(string idDevice);
	string getTemp(string idDevice);
	string Close();

private:
	sqlite3* db«Point;
	inline string selectValueFROMfrontData(string nameVarible);
	inline string selectValueFROMfrontTEMP(string nameVarible);
#if use—acheVariable == true
	string coolerSpeed;
	string pumpColor;
	string coolerColor;
	string switchAutoSpeedControl;
	string pumpSpeed;
	std::map <std::string, std::string> RAM;
	std::map <std::string, std::string> CPU;
	std::map <std::string, std::string> TEMP;

#endif // use—acheVariable == true

};
