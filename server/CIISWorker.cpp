#include <iostream>
#include <map>
#include <string>
#include <windows.h>//for GetEnvironmentVariableA
#include "CIISWorker.h"
#include "../Tools.h"


using namespace std;

void CIISWorker::out(string outputText) {//standard output
	if (newSession == true) {
		cout << "Content-Type: text/html\n\n";
		newSession = false;
	}
	cout << outputText;
	return;
}
string CIISWorker::getParametr(string name) {// get GET parameter
	std::map <std::string, std::string>::iterator it = getParMAP.find(name);
	return it== getParMAP.end()? "NULL" : getParMAP[name];
}
CIISWorker::CIISWorker() {
	newSession = true;

	char comment[256] = {};

	GetEnvironmentVariableA("QUERY_STRING", comment, 256);
	string getString;
	for (int i = 0; i < sizeof (comment) ; i++) {
		if (comment[i] == NULL) {
			break;
		}
		getString = getString + comment[i];
	}
	getString = "method=addData&temp=53777_memUsed=15000_cpu=0.05&devId=testStand";
	getString.insert(0, "_");
	getString.insert(getString.size(), "_");
	getString = HandlerSpecialCharacters(getString, "%2E", ".");
	getString = HandlerSpecialCharacters(getString, "%2C", ",");
	getString = HandlerSpecialCharacters(getString, "%28", "");
	getString = HandlerSpecialCharacters(getString, "%29", "");
	getString = HandlerSpecialCharacters(getString, "+", "");
	for (;;) {
		int rasp = getString.find("&");
		if (rasp == -1) {
			break;
		}
		getString[rasp] = '_';
	}
	int startPos = -1;
	for (;;) {
		startPos = getString.find("_", startPos + 1);
		if (startPos == -1) {
			break;
		}
		int equalSign = getString.find("=", startPos);
		int end = getString.find("_", startPos+1);
		if (end > equalSign) {
			getParMAP[SampleString(getString, startPos, equalSign)]= SampleString(getString, equalSign, end);
		}
		else {
			getParMAP[SampleString(getString, startPos, equalSign)];
		}

	}
	return;
}

