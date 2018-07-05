#pragma once
#include "Wall.h"
#include "Person.h"
#include "Space.h"
#include "SpaceOut.h"
#include "Target.h"
#include "TargetIn.h"
#include "Box.h"
class Level {
protected:
	int id;
	int** valueMap;
	
	int boxSum;
	int findBoxSum;

public:
	Element* map[14][16];
	Box box; Wall wall; Person person; Space space; SpaceOut spaceOut; Target target; TargetIn targetIn;
	Level() {}
	Level(int id,int valueMap[][16] ){}
	
	int getId() {
		return id;
	}

	//Element* getMap() {
	//	return map;
	//}

	int** getValueMap() {
		return valueMap;
	}

	int getBoxSum();
	int getFindBoxSum();
	void printMap();
	void moveBox(int direction);
	void setPersonPos();
	void synMap();
	int ** cloneValueMap();
//	void setBoxSum();
	bool tellIsWin();
};

