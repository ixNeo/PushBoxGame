#pragma once
#include "Element.h"

class Map {
private:
	int valueMap[14][16];
	Element* map[14][16];	
	int boxSum;
	int findBoxSum;
	Person person; Space space; SpaceOut spaceOut; Target target; TargetIn targetIn;
public:
	Map(){}
	Map(int** valueMap){
	}
	int getBoxSum();
	int getFindBoxSum();
	void printMap();
	void moveBox(int direction);
	void setPersonPos();
};
