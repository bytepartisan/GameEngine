#ifndef LOG_H
#define LOG_H

#include "Singleton.h"

class CLog : public Singleton<CLog>
{
public:
	CLog(){};
	~CLog(){};
	void Init(char* filename);
	void Write(char* msg);
	void WriteError(char* msg, int exception);
private:
	char* _filename;
};

#endif