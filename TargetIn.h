#pragma once
#include "Element.h"
class TargetIn :public Element {
//private:
//	string name;
public:
	TargetIn() :Element("targetIn") {}

	void printElement() {
		SelectColor(9);
		printf("¡î");
	}
};