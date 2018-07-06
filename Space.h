#pragma once
//#include <string>
using namespace std;
//#include "SelectColor.h"
extern void  SelectColor(int iColor);
class Element;
class Space :public Element {
//private:
//	string name;
public:
	Space() :Element(string("space")) {}

	void printElement() {
		printf("  ");
	}
};
