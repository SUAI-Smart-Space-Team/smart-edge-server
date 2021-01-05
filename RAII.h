#include "server/CIISWorker.h"
#include "db/CSQLiteDbWorker.h"

class RAII
{
public:
	CWebServerWorker* pWeb;
	CDbWorker* pDb;
	RAII() {
		pWeb = new CIISWorker;
		if (pWeb == NULL) {
			exit;
		}
		pDb = new CSQLiteDbWorker;
		if (pDb == NULL) {
			exit;
		}
	};
	~RAII() {
		delete pWeb;
		delete pDb;
	};
};

