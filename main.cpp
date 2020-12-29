#include <iostream>
#include <string>
#include "server/CIISWorker.h"
#include "RAII.h"

using namespace std;


int main()
{
    RAII server;
    if (server.pWeb->getParametr("method") == "example") {
        //event handle
    }
    return 0;
}