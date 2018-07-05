#pragma once
#include <string>
#include "SelectColor.h"
class Element {
protected:
	string name;
public:
	Element(){}
	Element(string name):name(name){}
	string getName() {
		return name;
	}
	virtual void printElement() {};
	/*ÎÄ×ÖÑÕÉ«º¯Êý*/

};
