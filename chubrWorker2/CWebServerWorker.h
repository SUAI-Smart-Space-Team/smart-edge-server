#include <string>

#pragma once
#pragma warning(disable : 4996)  

using namespace std;
class CWebServerWorker
{
public:
	virtual string out(string outputText) = 0;//standard output
	virtual string receiveGetPar()=0;// get GET parameters
};

