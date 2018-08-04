#pragma once
using namespace std;
#include "Element.h"

extern void  SelectColor(int iColor);
class Element;
class Person :public Element{
private:
	int x;
	int y;
public:
	Person(int x,int y):Element(string("person")),x(x),y(y){}
	Person() :Element(string("person")){ x = 0; y = 0; }
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void printElement() {
		SelectColor(10);
		printf("¡â");
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}
};