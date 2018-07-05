#pragma once
#include <string>
#include "Element.h"
class Person :public Element{
private:
	int x;
	int y;
public:
	Person(int x,int y):Element("person"),x(x),y(y){}
	Person() { x = 0; y = 0; }
	int setXY(int x, int y) {
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