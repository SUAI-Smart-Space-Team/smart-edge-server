#include <map>
#include <string>



class CWebServerWorker
{
public:
	virtual void out(std::string outputText, std::string ContentType)=0;
	virtual std::string getParametr(std::string name) = 0;
};

