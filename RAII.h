#include "server/CIISWorker.h"

class RAII
{
public:
	CWebServerWorker* pWeb;
	RAII() {
		pWeb = new CIISWorker;
		if (pWeb == NULL) {
			exit;
		}
	};
	~RAII() {
		delete pWeb;
	};
};

