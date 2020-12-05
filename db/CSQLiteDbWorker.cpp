#include "CSQLiteDbWorker.h"
#include <string>
#include "sqlite3.h"
#include "../Tools.h"
#include <time.h>



using namespace std;

string GetStringDate() {
	time_t rawtime = time(NULL);
	struct tm* timeinfo = localtime(&rawtime);
	string t;
	char comment[256];
	for (int i = 0; i < sizeof comment; i++) {
		comment[i] = NULL;
	}
	sprintf(comment, "%02d:%02d:%02d  %02d.%02d.%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
	for (int i = 0; i < sizeof comment; i++) {
		if (comment[i] == NULL) {
			break;
		}
		t = t + comment[i];
	}
	return t;
}

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


CSQLiteDbWorker::CSQLiteDbWorker()
: dbÇPoint(NULL) {
}

string CSQLiteDbWorker::init(string path) {//open db
	if (dbÇPoint) {
		Close();
	}
	char* zErrMsg = 0;
	int rc;
	char* sql;
	rc = sqlite3_open("chubrWorker.dblite", &dbÇPoint);
	if (rc) {
		return "error";
	}
	else {
		return "ok";
	}
}

string CSQLiteDbWorker::getPumpColor() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\"pumpColor\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getPumpSpeed() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\"pumpSpeed\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getCoolerColor() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\"coolerColor\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getCoolerSpeed() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select value FROM frontData WHERE nameVarible=\"coolerSpeed\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getTemp() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select temp FROM TEMP where ID = (select max(ID) FROM TEMP);";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getCPU() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select CPU FROM TEMP where ID = (select max(ID) FROM TEMP);";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getRAM() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select RAM FROM TEMP where ID = (select max(ID) FROM TEMP);";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}
string CSQLiteDbWorker::getidDevice() {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "select idDevice FROM TEMP where ID = (select max(ID) FROM TEMP);";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
	}
	return callbackStr;
}

string CSQLiteDbWorker::addData(string cpu, string mem, string temp, string devId) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "INSERT INTO TEMP(ID, idDevice, date, temp, CPU, RAM) "  \
			"VALUES(NULL, '" + devId + "', '" + "" + "', '" + temp + "', '" + cpu + "', '" + mem + "'); ";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return errBd;
}

CSQLiteDbWorker::~CSQLiteDbWorker() {
	Close();
	return;
}

string CSQLiteDbWorker::Close()
{
	sqlite3_close(dbÇPoint);
	dbÇPoint = NULL;
	return string();
}

string CSQLiteDbWorker::setCoolerSpeed(string arg) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "UPDATE frontData SET value = \'" + arg + "\' WHERE nameVarible = \"coolerSpeed\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return zErrMsg;
}
string CSQLiteDbWorker::setPumpColor(string arg) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "UPDATE frontData SET value = \'" + arg + "\' WHERE nameVarible = \"pumpColor\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return zErrMsg;
}
string CSQLiteDbWorker::setCoolerColor(string arg) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "UPDATE frontData SET value = \'" + arg + "\' WHERE nameVarible = \"coolerColor\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return zErrMsg;
}
string CSQLiteDbWorker::setSwitchAutoSpeedControl(string arg) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "UPDATE frontData SET value = \'" + arg + "\' WHERE nameVarible = \"switchAutoSpeedControl\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return zErrMsg;
}
string CSQLiteDbWorker::setPumpSpeed(string arg) {
	char* zErrMsg = 0;
	if (dbÇPoint != NULL) {
		string resp = "UPDATE frontData SET value = \'" + arg + "\' WHERE nameVarible = \"pumpSpeed\";";
		int rc = sqlite3_exec(dbÇPoint, resp.c_str(), callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			for (int i = 0;; i++) {
				if (zErrMsg[i] == '\0') {
					break;
				}
				errBd += zErrMsg[i];
			}
			sqlite3_free(zErrMsg);
		}
		else {
			return "ok";
		}
	}
	return zErrMsg;
}