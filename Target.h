#pragma once
#include "Element.h"
class Target :public Element {
//private:
//	string name;
public:
	Target() :Element("target") {}

	void printElement() {
		SelectColor(11);    /*Ä¿µÄµØ*/
		printf("¡ð");
	}
};