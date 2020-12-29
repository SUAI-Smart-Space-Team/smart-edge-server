#include <string>
#include <iostream>
#include <windows.h>
#include "CIISWorker.h"
#include "../Tools.h"


using namespace std;

string CIISWorker::out(string outputText) {//standard output
	if (newSession == true) {
		cout << "Content-Type: text/html\n\n";
		newSession = false;
	}
	cout << outputText;
	return "";
}
string CIISWorker::receiveGetPar() {// get GET parameters
	char comment[256];
	for (int i = 0; i < sizeof comment; i++) {
		comment[i] = NULL;
	}


	GetEnvironmentVariableA("QUERY_STRING", comment, 256);
	string getString;
	for (int i = 0; i < 255; i++) {
		if (comment[i] == NULL) {
			break;
		}
		getString = getString + comment[i];
	}
	//getString = "chubrWorker.cgi?method=addData&temp=53777_memUsed=15000_cpu=0.05&devId=testStand";
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
	//out(getString+"<br>");
	return getString;
}
CIISWorker::CIISWorker() {
	newSession = true;
	return;
}

