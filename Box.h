#pragma once
using namespace std;
#include "Element.h"

extern void  SelectColor(int iColor);
class Element;
class Box :public Element {
public:
	Box() :Element(string("box")) {}

	void printElement() {
		SelectColor(11);
		printf("¡ñ");
	}
};