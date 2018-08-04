#pragma once

using namespace std;
#include "Element.h"
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
	int valueMap[14][16]; // 数据地图，方便处理
	int valueMap2[14][16]; // 数据地图副本，在人物移动后的更新地图函数中用
	int boxSum;  // 箱子总数
	int findBoxSum;  // 已经找到的箱子数目

public:
	// 某一类型的集合类
	Box box = Box(); Wall wall = Wall(); Person person = Person(); 
	Space space = Space(); SpaceOut spaceOut = SpaceOut(); Target target = Target(); TargetIn targetIn = TargetIn();
	Element* map[14][16];  // 真实存储类型的地图
	Level() {}
	Level(int id, int valueMap[14][16]);
	
	int getId() {
		return id;
	}

	//Element* getMap() {
	//	return map;
	//}

	Level operator = (Level a); // 深复制
	int getBoxSum();  // 得到箱子总数
	int getFindBoxSum();// 得到成功的箱子数
	void printMap(); // 根据地图打印界面
	void moveBox(int direction);  // 移动箱子
	void setPersonPos();  // 设置人物坐标
	void synMap();  // 同步数据地图和真实地图
	bool tellIsWin();  // 判断是否胜利
};

