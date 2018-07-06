#pragma once
#include <string>
using namespace std;
class Element {
protected:
	string name;
public:
	Element():name(string("none") ){}
	Element(string name) :name(name){ }
	string getName() {
		return name;
	}
	virtual void printElement()=0;

};
