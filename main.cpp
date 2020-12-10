#include <iostream>
#include <string>
#include "db/CSQLiteDbWorker.h"
#include "server/CIISWorker.h"
#include "Tools.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"



using namespace rapidjson;


string addData(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {
	string temp = SampleString(postPar, (int)postPar.find("temp") + 4, (int)postPar.find("_", (int)postPar.find("temp")));
	temp = to_string(atoi(temp.c_str()) / 1000) + "." + to_string(atoi(temp.c_str()) % 1000);

	string cpu = SampleString(postPar, (int)postPar.find("cpu") + 3, (int)postPar.find("_", (int)postPar.find("cpu")));

	string mem = SampleString(postPar, (int)postPar.find("memUsed") + 7, (int)postPar.find("_", (int)postPar.find("memUsed")));
	string devId = SampleString(postPar, (int)postPar.find("=", (int)postPar.find("devId")), (int)postPar.find("_", (int)postPar.find("devId")));

	//pWeb->out(createrJson("result", "ok", 0, ""));
	string answer = pDB->addData(cpu, mem, temp, devId);
	if (answer != "ok") {
		pWeb->out(createrJson("error", answer, 0, ""));
	}
	else {
		pWeb->out(createrJson("result", "ok", 0, ""));
	}
	return "ok";
}


string getConfiguration(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {

	string json;

	json = createrJson("pumpColor", pDB->getPumpColor(), 0, json);

	json = createrJson("coolerColor", pDB->getCoolerColor(), 0, json);

	json = createrJson("pumpSpeed", pDB->getPumpSpeed(), 0, json);

	json = createrJson("coolerSpeed", pDB->getCoolerSpeed(), 0, json);

	pWeb->out(json);
	return "ok";
}


string getTelemetry(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {

	string json;

	json = createrJson1("pumpColor", pDB->getPumpColor(), 0, json);

	json = createrJson1("coolerColor", pDB->getCoolerColor(), 0, json);

	json = createrJson1("pumpSpeed", pDB->getPumpSpeed(), 0, json);

	json = createrJson1("coolerSpeed", pDB->getCoolerSpeed(), 0, json);

	json = createrJson1("temp", pDB->getTemp(), 0, json);

	json = createrJson1("CPU", pDB->getCPU(), 0, json);

	json = createrJson1("memUsed", pDB->getRAM(), 0, json);

	json = createrJson1("idDevice", pDB->getidDevice(), 0, json);

	pWeb->out(json);
	return "ok";
}

string setValue(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {
	int pos = -1;
	postPar = HandlerSpecialCharacters(postPar, "rgb", "");
	bool ref = false;
	string error;

	rapidjson::Document json;
	json.SetObject();
	rapidjson::Document::AllocatorType& allocator = json.GetAllocator();
	for (;;) {
		rapidjson::Value object(rapidjson::kObjectType);
		pos = postPar.find("=", pos + 1);
		if (pos == -1) {
			break;
		}
		int nach = postPar.rfind("_", pos);
		int kon = postPar.find("_", pos);
		string nameVariable = SampleString(postPar, nach, pos);
		string  arg = SampleString(postPar, pos, kon);
		string sqlRequest;
		string req;

		if (nameVariable == "coolerSpeed") {
			req = pDB->setCoolerSpeed(arg);
		}
		if (nameVariable == "pumpColor") {
			req = pDB->setPumpColor(arg);
		}
		if (nameVariable == "coolerColor") {
			req = pDB->setCoolerSpeed(arg);
		}
		if (nameVariable == "switchAutoSpeedControl") {
			req = pDB->setSwitchAutoSpeedControl(arg);
		}
		if (nameVariable == "pumpSpeed") {
			req = pDB->setPumpSpeed(arg);
		}
		if (req != "") {
			if (req == "ok") {
				rapidjson::Value object(rapidjson::kObjectType);
				object.AddMember("result", "ok", allocator);
				//object.AddMember("nameVariable", arg.c_str(), allocator);
				//jsonStr = createrJson("ok", nameVariable + "=" + arg, 0, json);
			}
			else {
				//jsonStr = createrJson("error", req, 0, json);
				object.AddMember("result", "error", allocator);
			}
		}
	}
	if (ref == true) {
		pWeb->out("");
	}
	//if (json == "") {
	//	//standartOut(createrJson("error", "Invalid argument nameVariable", 0, ""));
	//	pWeb->out("<html><head><meta http-equiv =\"refresh\" content =\"1;URL=https://suai.chupr.ru\"/></head></html>");

	//}
	//else {
	//	//standartOut(json);
	//	pWeb->out("<html><head><meta http-equiv =\"refresh\" content =\"1;URL=https://suai.chupr.ru\"/></head></html>");

	//}
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	json.Accept(writer);
	pWeb->out(buffer.GetString());
	return "ok";
}

int main()
{
	CDbWorker* pDB = new  CSQLiteDbWorker;

	pDB->init("");
	CWebServerWorker* pWeb = new CIISWorker;
	string par = pWeb->receiveGetPar();
	string method = SampleString(par, (int)par.find("=", (int)par.find("method")), (int)par.find("_", (int)par.find("method")));
	if (method == "addData") {
		addData(par, pWeb, pDB);
		delete pWeb;
		delete pDB;
		return 0;
	}
	if (method == "getConfiguration") {
		getConfiguration(par, pWeb, pDB);
		delete pWeb;
		delete pDB;
		return 0;
	}
	if (method == "getTelemetry") {
		getTelemetry(par, pWeb, pDB);
		delete pWeb;
		delete pDB;
		return 0;
	}

	if (method == "setValue") {
		setValue(par, pWeb, pDB);
		delete pWeb;
		delete pDB;
		return 0;
	}
	pWeb->out(createrJson("error", "Invalid argument method", 0, ""));
	delete pWeb;
	delete pDB;
	return 0;

}
