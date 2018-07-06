#pragma once
using namespace std;
#include "Element.h"
extern void  SelectColor(int iColor);
class Element;
class TargetIn :public Element {
public:
	TargetIn() :Element(string("targetIn")) {}

	void printElement() {
		SelectColor(9);
		printf("¡î");
	}
};