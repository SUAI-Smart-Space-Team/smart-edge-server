#include <map>
#include <string>



class CWebServerWorker
{
public:
	virtual void out(std::string outputText) = 0;//standard output
	virtual std::string getParametr(std::string name) = 0;
};

