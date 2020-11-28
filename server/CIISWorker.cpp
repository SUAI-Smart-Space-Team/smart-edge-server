#include "CIISWorker.h"
#include <string>
#include <iostream>
#include <windows.h>
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
	char szName[1024];
	for (int i = 0; i < sizeof comment; i++) {
		szName[i] = NULL;
	}
	GetEnvironmentVariableA("QUERY_STRING", comment, 256);
	string getString;
	for (int i = 0; i < 255; i++) {
		if (comment[i] == NULL) {
			break;
		}
		getString = getString + comment[i];
	}
	getString = "chubrWorker.cgi?method=setValue&pumpSpeed=123&pumpColor=aaa&coolerSpeed=456&coolerColor=zzz";
	getString = "_" + getString + "_";
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

