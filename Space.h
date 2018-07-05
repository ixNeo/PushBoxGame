#pragma once
#include <string>
class Space :public Element {
//private:
//	string name;
public:
	Space() :Element("space") {}

	void printElement() {
		printf("  ");
	}
};
