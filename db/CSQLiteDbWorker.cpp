#include <string>
#include "sqlite3.h"
#include <time.h>
#include "CSQLiteDbWorker.h"
#include "../config.h"
#include "../Tools.h"




using namespace std;


string callbackStr;
string errBd;
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	//int i;
	//for (i = 0; i < argc; i++) {
		//sprintf(,"%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	//}
	//printf("\n");
	callbackStr.clear();
	for (int i = 0; i < argc; i++) {
		callbackStr += argv[i];
	}
	return 0;
}



string CSQLiteDbWorker::init(string path) {//open db
	if (dbÇPoint) {
		Close();
	}
	char* zErrMsg = 0;
	int rc = 0;
	char* sql = NULL;
	rc = sqlite3_open("chubrWorker.dblite", &dbÇPoint);
	if (rc) {
		return "error";
	}
	else {
		return "ok";
	}
#if	useÑacheVariable == true
	coolerSpeed="null";
	pumpColor = "null";
	coolerColor = "null";
	switchAutoSpeedControl = "null";
	pumpSpeed = "null";
#endif // useÑacheVariable == true
	return "ok";
}

CSQLiteDbWorker::CSQLiteDbWorker() {
	if (init("chubrWorker.dblite") == "error") {
		exit;
	}
	return;
}
CSQLiteDbWorker::~CSQLiteDbWorker() {
	Close();
}

string CSQLiteDbWorker::Close()
{
	sqlite3_close(dbÇPoint);
	dbÇPoint = NULL;
	return "ok";
}




inline string CSQLiteDbWorker::selectValueFROMfrontData(string nameVarible) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\""+ nameVarible +"\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
inline string CSQLiteDbWorker::selectValueFROMfrontTEMP(string nameVarible) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM TEMP WHERE nameVarible=\"" + nameVarible + "\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
	}





string CSQLiteDbWorker::getPumpColor() {
#if	useÑacheVariable == true
	if (pumpColor != "null")
		return pumpColor;
#endif // useÑacheVariable == true
	return selectValueFROMfrontData("pumpColor");
}


string CSQLiteDbWorker::getPumpSpeed() {
#if	useÑacheVariable == true
	if (pumpSpeed != "null")
		return pumpSpeed;
#endif // useÑacheVariable == true
	return selectValueFROMfrontData("pumpSpeed");
}


string CSQLiteDbWorker::getCoolerColor() {
#if	useÑacheVariable == true
	if (coolerColor != "null")
		return coolerColor;
#endif // useÑacheVariable == true
	return selectValueFROMfrontData("coolerColor");
}


string CSQLiteDbWorker::getCoolerSpeed() {
#if	useÑacheVariable == true
	if (coolerSpeed != "null")
		return coolerSpeed;
#endif // useÑacheVariable == true
	return selectValueFROMfrontData("coolerSpeed");
}




string CSQLiteDbWorker::getTemp(string idDevice) {
#if	useÑacheVariable == true
	std::map <std::string, std::string>::iterator it = TEMP.find(idDevice);
	if (it != TEMP.end()) {
		return TEMP[idDevice];
	}
#endif // useÑacheVariable == true
	return selectValueFROMfrontTEMP("temp");
}


string CSQLiteDbWorker::getCPU(string idDevice) {
#if	useÑacheVariable == true
	std::map <std::string, std::string>::iterator it = CPU.find(idDevice);
	if (it != CPU.end()) {
		return CPU[idDevice];
	}
#endif // useÑacheVariable == true
	return selectValueFROMfrontTEMP("CPU");
}



string CSQLiteDbWorker::getRAM(string idDevice) {
#if	useÑacheVariable == true
	std::map <std::string, std::string>::iterator it = RAM.find(idDevice);
	if (it != RAM.end()) {
		return RAM[idDevice];
	}
#endif // useÑacheVariable == true
	return selectValueFROMfrontTEMP("RAM");
}