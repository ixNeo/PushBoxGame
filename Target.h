#pragma once
using namespace std;
#include "Element.h"
//#include "SelectColor.h"

extern void  SelectColor(int iColor);
class Element;
class Target :public Element {
//private:
//	string name;
public:
	Target() :Element(string("target")) {}

	void printElement() {
		SelectColor(11);    /*Ä¿µÄµØ*/
		printf("¡ð");
	}
};

