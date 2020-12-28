#include <iostream>
#include <string>
#include "server/CIISWorker.h"


using namespace std;


int main()
{
    CWebServerWorker* pWeb = new CIISWorker;
    if (pWeb->getParametr("method") == "addData") {
        int i = 0;
        i++;
        //event handler
    }
    delete pWeb;
    return 0;
}