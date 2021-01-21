#include <iostream>
#include <string>
#include "json/json\json.h"
#include "server/CIISWorker.h"
#include "db/CSQLiteDbWorker.h"
#include "RAII.h"

using namespace std;

string getInfo(CWebServerWorker* pWeb, CDbWorker* pDB) {
	Json::Value jsonR;
	jsonR["buildDate"] = __DATE__;
	pWeb->out("[" + jsonR.toStyledString() + "]", "json");
	return "ok";
}

string getTelemetry(CWebServerWorker* pWeb, CDbWorker* pDB) {
	Json::Value jsonR;
	if (pWeb->getParametr("deviceId") == "NULL") {
		jsonR["error"] = "Invalid deviceId";
		pWeb->out(jsonR.toStyledString(), "json");
		return "error";
	}
	
	jsonR["pumpColor"] = pDB->getPumpColor();
	jsonR["coolerColor"] = pDB->getCoolerColor();
	jsonR["pumpSpeed"] = pDB->getPumpSpeed();
	jsonR["coolerSpeed"] = pDB->getCoolerSpeed();
	jsonR["temp"] = pDB->getTemp(pWeb->getParametr("deviceId"));
	jsonR["CPU"] = pDB->getCPU(pWeb->getParametr("deviceId"));
	jsonR["memUsed"] = pDB->getRAM(pWeb->getParametr("deviceId"));
	jsonR["idDevice"] = pWeb->getParametr("deviceId");
	pWeb->out("["+jsonR.toStyledString()+"]","json");

	return "ok";
}
string setValue(CWebServerWorker* pWeb, CDbWorker* pDB) {

	return "ok";
}
int main()
{
    RAII server;

	if (server.pWeb->getParametr("method") == "getTelemetry") {
		getTelemetry(server.pWeb, server.pDb);
		return 0;
	}
	if (server.pWeb->getParametr("method") == "getInfo") {
		getInfo(server.pWeb, server.pDb);
		return 0;
	}

    Json::Value jsonR;   // starts as "null"; will contain the root value after parsing

    jsonR["error"] = "Invalid argument method";
    jsonR["method"] = server.pWeb->getParametr("method");
    server.pWeb->out("["+jsonR.toStyledString()+ "]","json");


    return 0;
}