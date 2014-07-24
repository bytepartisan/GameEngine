#include <iostream>
#include <fstream>
using namespace std;
#include "Log.h"

void CLog::Init(char* filename){
	this->_filename = filename;
}

void CLog::Write(char* msg){
	ofstream logfile(this->_filename, ios::out | ios::app );
	if(logfile.is_open())
	{
		logfile << msg << endl;
		logfile.close();
	}
}

void CLog::WriteError(char *msg, int exception){
	ofstream logfile(this->_filename, ios::out | ios::app );
	if(logfile.is_open())
	{
		logfile << "Error(" << exception << "): " << msg << endl;
		logfile.close();
	}
}