#ifndef SETTINGS_H
#define SETTINGS_H

#include "Singleton.h"

class CSettings : public Singleton<CSettings>
{
public:
	CSettings(){}
	~CSettings(){}

	void Init();

	int screenWidth;
	int screenHeight;
	int screenBpp;

private:
	
};

#endif