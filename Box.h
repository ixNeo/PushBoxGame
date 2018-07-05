#pragma once
#include "Element.h"
class Box :public Element {
//private:
//	string name;
public:
	Box() :Element("box") {}

	void printElement() {
		SelectColor(11);
		printf("¡ñ");
	}
};