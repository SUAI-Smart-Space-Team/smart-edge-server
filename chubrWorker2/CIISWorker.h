#pragma once
#include "CWebServerWorker.h"
class CIISWorker :
    public CWebServerWorker
{
public:
    string out(string outputText);//standard output
    string receiveGetPar();// get GET parameters
    CIISWorker();
private:
    bool newSession;
};

