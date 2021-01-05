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
	if (db�Point) {
		Close();
	}
	char* zErrMsg = 0;
	int rc = 0;
	char* sql = NULL;
	rc = sqlite3_open("chubrWorker.dblite", &db�Point);
	if (rc) {
		return "error";
	}
	else {
		return "ok";
	}
#if	use�acheVariable == true
	coolerSpeed="null";
	pumpColor = "null";
	coolerColor = "null";
	switchAutoSpeedControl = "null";
	pumpSpeed = "null";
#endif // use�acheVariable == true
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
	sqlite3_close(db�Point);
	db�Point = NULL;
	return "ok";
}




inline string CSQLiteDbWorker::selectValueFROMfrontData(string nameVarible) {
	char* zErrMsg = 0;
	if (db�Point != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\""+ nameVarible +"\";";
		int rc = sqlite3_exec(db�Point, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
inline string CSQLiteDbWorker::selectValueFROMfrontTEMP(string nameVarible) {
	char* zErrMsg = 0;
	if (db�Point != NULL) {
		string resp = "select value FROM TEMP WHERE nameVarible=\"" + nameVarible + "\";";
		int rc = sqlite3_exec(db�Point, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
	}





string CSQLiteDbWorker::getPumpColor() {
#if	use�acheVariable == true
	if (pumpColor != "null")
		return pumpColor;
#endif // use�acheVariable == true
	return selectValueFROMfrontData("pumpColor");
}


string CSQLiteDbWorker::getPumpSpeed() {
#if	use�acheVariable == true
	if (pumpSpeed != "null")
		return pumpSpeed;
#endif // use�acheVariable == true
	return selectValueFROMfrontData("pumpSpeed");
}


string CSQLiteDbWorker::getCoolerColor() {
#if	use�acheVariable == true
	if (coolerColor != "null")
		return coolerColor;
#endif // use�acheVariable == true
	return selectValueFROMfrontData("coolerColor");
}


string CSQLiteDbWorker::getCoolerSpeed() {
#if	use�acheVariable == true
	if (coolerSpeed != "null")
		return coolerSpeed;
#endif // use�acheVariable == true
	return selectValueFROMfrontData("coolerSpeed");
}




string CSQLiteDbWorker::getTemp(string idDevice) {
#if	use�acheVariable == true
	std::map <std::string, std::string>::iterator it = TEMP.find(idDevice);
	if (it != TEMP.end()) {
		return TEMP[idDevice];
	}
#endif // use�acheVariable == true
	return selectValueFROMfrontTEMP("temp");
}


string CSQLiteDbWorker::getCPU(string idDevice) {
#if	use�acheVariable == true
	std::map <std::string, std::string>::iterator it = CPU.find(idDevice);
	if (it != CPU.end()) {
		return CPU[idDevice];
	}
#endif // use�acheVariable == true
	return selectValueFROMfrontTEMP("CPU");
}



string CSQLiteDbWorker::getRAM(string idDevice) {
#if	use�acheVariable == true
	std::map <std::string, std::string>::iterator it = RAM.find(idDevice);
	if (it != RAM.end()) {
		return RAM[idDevice];
	}
#endif // use�acheVariable == true
	return selectValueFROMfrontTEMP("RAM");
}