#pragma once
#include "CWebServerWorker.h"
#include <map>


class CIISWorker :
    public CWebServerWorker
{
public:
    std::string out(std::string outputText);//standard output
    std::string getParametr(std::string name);
    CIISWorker();
private:
    bool newSession;
    std::map <std::string, std::string> getParMAP;
};

