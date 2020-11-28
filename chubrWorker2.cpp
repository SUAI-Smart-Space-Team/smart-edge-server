// chubrWorker2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CSQLiteDbWorker.h"
#include "CIISWorker.h"
#include <string>
#include "Tools.h"




string addData(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {
	string temp = SampleString(postPar, (int)postPar.find("temp") + 4, (int)postPar.find("_", (int)postPar.find("temp")));
	temp = to_string(atoi(temp.c_str()) / 1000) + "." + to_string(atoi(temp.c_str()) % 1000);

	string cpu = SampleString(postPar, (int)postPar.find("cpu") + 3, (int)postPar.find("_", (int)postPar.find("cpu")));

	string mem = SampleString(postPar, (int)postPar.find("memUsed") + 7, (int)postPar.find("_", (int)postPar.find("memUsed")));
	string devId = SampleString(postPar, (int)postPar.find("=", (int)postPar.find("devId")), (int)postPar.find("_", (int)postPar.find("devId")));

	pWeb->out(createrJson("result", "ok", 0, ""));
	pDB->addData(cpu, mem, temp, devId);
	return "";
}


string getConfiguration(string postPar, CWebServerWorker* pWeb, CDbWorker* pDB) {

	string json;

	json = createrJson("pumpColor", pDB->getPumpColor(), 0, json);

	json = createrJson("coolerColor", pDB->getCoolerColor(), 0, json);

	json = createrJson("pumpSpeed", pDB->getPumpSpeed(), 0, json);

	json = createrJson("coolerSpeed", pDB->getCoolerSpeed(), 0, json);

	pWeb->out(json);
	return "";
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
	return "";
}


int main()
{
//    CSQLiteDbWorker db;
    CDbWorker* pDB = new  CSQLiteDbWorker;

    pDB->init("");
    CWebServerWorker* pWeb = new CIISWorker;
    string par = pWeb->receiveGetPar();
	string method = SampleString(par, (int)par.find("=", (int)par.find("method")), (int)par.find("_", (int)par.find("method")));
	if (method == "addData") {
		addData(par, pWeb, pDB);
		return 0;
	}
	if (method == "getConfiguration") {
		getConfiguration(par, pWeb, pDB);
		return 0;
	}
	if (method == "getTelemetry") {
		getTelemetry(par, pWeb, pDB);
		return 0;
	}

	//if (method == "setValue") {
	//	//setValue(getPar);
	//	return 0;
	//}
	pWeb->out(createrJson("error", "Invalid argument method", 0, ""));
	return 0;

    
    delete pWeb;
    delete pDB;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
