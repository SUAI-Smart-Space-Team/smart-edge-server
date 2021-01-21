#include <map>
#include "CWebServerWorker.h"
#pragma once

class CIISWorker :
    public CWebServerWorker
{
public:
    void out(std::string outputText, std::string ContentType);
    std::string getParametr(std::string name);
    CIISWorker();
private:
    bool newSession;
    std::map <std::string, std::string> getParMAP;
};

