#include <string>



#pragma once


#pragma warning(disable : 4996)  

using namespace std;

class CDbWorker
{
public:
	virtual string init(string path)=0;//open Db
	virtual string addData(string cpu, string mem, string temp, string devId)=0;
	virtual string getPumpColor()=0;
	virtual ~CDbWorker();
	virtual string getCoolerColor() = 0;
	virtual string getPumpSpeed() = 0;
	virtual string getCoolerSpeed() = 0	;

	virtual string getidDevice() = 0;
	virtual string getRAM() = 0;
	virtual string getCPU() = 0;
	virtual string getTemp() = 0;

	virtual string setCoolerSpeed(string arg) = 0;
	virtual string setPumpColor(string arg) = 0;
	virtual string setCoolerColor(string arg) = 0;
	virtual string setSwitchAutoSpeedControl(string arg) = 0;
	virtual string setPumpSpeed(string arg) = 0;

};

