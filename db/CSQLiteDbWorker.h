#pragma once
#include "CDbWorker.h"
#include "sqlite3.h"
#include "Tools.h"
class CSQLiteDbWorker :
	public CDbWorker
{
public:
	CSQLiteDbWorker();
	string init(string path);//open Db
	string addData(string cpu, string mem, string temp, string devId);
	~CSQLiteDbWorker();
	string getPumpColor();
	string getCoolerColor();
	string getPumpSpeed();
	string getCoolerSpeed();

	string getidDevice();
	string getRAM();
	string getCPU();
	string getTemp();


	string setCoolerSpeed(string arg);
	string setPumpColor(string arg);
	string setCoolerColor(string arg);
	string setSwitchAutoSpeedControl(string arg);
	string setPumpSpeed(string arg);
private:
	sqlite3* db«Point;
public:
	string Close();
};
