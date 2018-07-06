#pragma once
#include <string>
using namespace std;
#include "Element.h"
extern void  SelectColor(int iColor);

class Element;
class Wall :public Element {
public:
	Wall() :Element(string("wall")) {}

	void printElement() {
		SelectColor(14);    /*Ç½*/
		printf("¨ˆ");

	}
};