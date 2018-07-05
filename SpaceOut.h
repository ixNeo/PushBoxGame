#pragma once
#include "Element.h"
class SpaceOut :public Element {
//private:
//	string name;
public:
	SpaceOut() :Element("spaceOut") {}

	void printElement() {
		printf("  ");
	}
};
