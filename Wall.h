#pragma once
#include "Element.h"
#include <string>

class Wall :public Element {
//private:
//	string name;
public:
	Wall() :Element("wall") {}

	void printElement() {
		SelectColor(14);    /*Ç½*/
		printf("¨ˆ");

	}
};