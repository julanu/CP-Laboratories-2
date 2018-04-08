#ifndef STRCLASS_H
#define STRCLASS_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class StrClass
{
	private:
		char* str;
	
	public:
		StrClass();
		StrClass(char* str);
		~StrClass();
		char* getStr();
		void setStr(char* str);
		int getLength();
		int lastOccurence(char ch);
		char* strUp();
		int numOccurence(char ch);
};

#endif
