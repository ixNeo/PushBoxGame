#pragma once
using namespace std;
#include "Element.h"
class Element;
class SpaceOut :public Element {
public:
	SpaceOut() :Element(string("spaceOut")) {}

	void printElement() {
		printf("  ");
	}
};
