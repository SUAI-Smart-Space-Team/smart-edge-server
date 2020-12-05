//Tools.cpp v1.0
#include "Tools.h"
#include <string>
#include "time.h"

using namespace std;
#pragma warning(disable : 4996)  


 
string SampleString(string arg,int from,int to){
	string str;
	for(int i=from+1;i<to;i++){
		str=str+arg[i];
	}
	return str;
} 
string GetStringMon(){
	time_t rawtime = time (NULL);
	struct tm*	timeinfo = localtime (&rawtime);
	char cmd[100];
	for (int i=0;i<100;i++){
		cmd[i]=0;
	}
	sprintf (cmd, "%d-%d", timeinfo->tm_year+1900,timeinfo->tm_mon+1);
	string tmplog;
	for (int i=0;i<100;i++){
		if(cmd[i]!=0){
			tmplog=tmplog+cmd[i];
		}
	}
	return tmplog;
}
//string GetStringDate() {
//    time_t rawtime = time(NULL);
//    struct tm* timeinfo = localtime(&rawtime);
//    string t;
//    char comment[256];
//    for (int i = 0; i < sizeof comment; i++) {
//        comment[i] = NULL;
//    }
//    sprintf(comment, "%02d:%02d:%02d  %02d.%02d.%d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
//    for (int i = 0; i < sizeof comment; i++) {
//        if (comment[i] == NULL) {
//            break;
//        }
//        t = t + comment[i];
//    }
//    return t;
//}


string createrJson(string namePar, string strPar, int intPar, string oldJson) {
    if (oldJson != "") {
        oldJson = SampleString(oldJson, (int)oldJson.find("["), (int)oldJson.find("]"));
    }
    string json;
    if (strPar == "") {
        json = "{\"" + namePar + "\":" + to_string(intPar) + "}";
    }
    else {
        json = "{\"" + namePar + "\":\"" + strPar + "\"}";
    }
    if (oldJson != "") {
        return "[" + oldJson + "," + json + "]";
    }
    else {
        return "[" + json + "]";
    }
}
string createrJson1(string namePar, string strPar, int intPar, string oldJson) {
    if (oldJson != "") {
        oldJson = SampleString(oldJson, (int)oldJson.find("[") + 1, (int)oldJson.find("]") - 1);
    }
    string json;
    if (strPar == "") {
        json = "\"" + namePar + "\":" + to_string(intPar) + "";
    }
    else {
        json = "\"" + namePar + "\":\"" + strPar + "\"";
    }
    if (oldJson != "") {
        return "[{" + oldJson + "," + json + "}]";
    }
    else {
        return "[{" + json + "}]";
    }
}
string HandlerSpecialCharacters(string url, string designation, string  replacement) {
    int nach = 0;
    int kon = 0;
    string url1;
    for (;;) {
        int tmp = url.find(designation);
        if (tmp == -1) {
            break;
        }
        url1 = SampleString(url, nach - 1, tmp) + replacement;
        url1 += SampleString(url, tmp + designation.size() - 1, url.size());
        url = url1;
    }
    return url;
}