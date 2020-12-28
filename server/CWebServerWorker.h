#include <string>
#include <map>
#pragma once


class CWebServerWorker
{
public:
	virtual std::string out(std::string outputText) = 0;//standard output
	virtual std::string getParametr(std::string name) = 0;
};

