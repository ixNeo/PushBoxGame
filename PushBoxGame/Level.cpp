#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
#include "Level.h"

const int SPACE_OUT = 0;
const int WALL = 1;
const int SPACE = 2;
const int TARGET = 3;
const int BOX = 4;
const int TARGET_IN = 5;
const int PERSON = 6;


void  SelectColor(int iColor)                  //颜色函数
{
	HANDLE  hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));//得到控制台输出设备的句柄
	SetConsoleTextAttribute(hConsole, iColor);//设置控制台设备的属性
}

Level Level::operator = (Level a) {
	this->id = a.id;
	boxSum = 0;
	findBoxSum = 0;

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 16; j++) {
			this->valueMap[i][j] = a.valueMap[i][j];
			this->valueMap2[i][j] = a.valueMap2[i][j];
			switch (valueMap[i][j]) {
			case 0:
				map[i][j] = &spaceOut; break;
			case 1:
				map[i][j] = &wall; break;
			case 2:
				map[i][j] = &space; break;
			case 3:
				map[i][j] = &target; break;
			case 4:
				map[i][j] = &box; break;
			case 5:
				map[i][j] = &targetIn; break;
			case 6:
				map[i][j] = &person; break;
			default:break;
			}
		}
	}
	return *this;
}

Level::Level(int id, int valueMap[14][16]) {
	this->id = id;
	boxSum = 0;
	findBoxSum = 0;
	
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 16; j++) {
			this->valueMap[i][j] = valueMap[i][j];
			this->valueMap2[i][j] = valueMap[i][j];
			switch (valueMap[i][j]) {
			case 0:
				map[i][j] = &spaceOut; break;
			case 1:
				map[i][j] = &wall; break;
			case 2:
				map[i][j] = &space; break;
			case 3:
				map[i][j] = &target; break;
			case 4:
				map[i][j] = &box; break;
			case 5:
				map[i][j] = &targetIn; break;
			case 6:
				map[i][j] = &person; break;
			default:break;
			}
		}
	}
	//getchar();
}

void Level::synMap()
{
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 16; j++) {
			switch (valueMap[i][j]) {
			case 0:
				map[i][j] = &spaceOut; break;
			case 1:
				map[i][j] = &wall; break;
			case 2:
				map[i][j] = &space; break;
			case 3:
				map[i][j] = &target; break;
			case 4:
				map[i][j] = &box; break;
			case 5:
				map[i][j] = &targetIn; break;
			case 6:
				map[i][j] = &person; break;
			default:break;
			}
		}
	}
}
int Level::getBoxSum() {
	boxSum = 0;
	for (int i = 0; i<14; i++)
		for (int j = 0; j<16; j++) {
			if (map[i][j] == &target || map[i][j] == &targetIn) /*记录箱子个数*/
				boxSum++;		
		}
	return boxSum;
}

int Level::getFindBoxSum() {
	findBoxSum = 0;
	for (int i = 0; i<14; i++)
		for (int j = 0; j<16; j++) {
			if (map[i][j] == &targetIn)
				findBoxSum++;			
		}
	return findBoxSum;
}

bool Level::tellIsWin() {
	if (getBoxSum() == getFindBoxSum())
		return true;
	else
		return false;

}

void Level::printMap() {
	int i, j;
	for (i = 0; i<14; i++) {
		for (j = 0; j<16; j++)
		{
			map[i][j]->printElement();
		}
		cout << endl;
	}
	SelectColor(14);
	cout << endl;
	cout << "\tYou are in Level " << getId()+1 << "!\t\t" << endl;
	cout << "\tPress arrow keys to play the game!\t" << endl;
	cout << "\tpress N to the next level!\t" << endl;
	cout << "\tpress Q to return the home page!\t" << endl;
}

void Level::setPersonPos() {
	for (int i = 0; i<14; i++) {
		for (int j = 0; j < 16; j++) {
			if (map[i][j] == &person) {
				person.setXY(i, j);
			}
		}
	}
}


void Level::moveBox(int iSelect) {
	int iPlayerX1, iPlayerY1;        /*小人下一个要走的位置坐标*/
	int iPlayerX2, iPlayerY2;        /*小人下下一个要走的位置坐标*/
	setPersonPos();
	int iPlayerX = person.getX(), iPlayerY = person.getY();
	switch (iSelect) {
	case 1:        /*向上移动*/
		iPlayerX1 = iPlayerX - 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX - 2;
		iPlayerY2 = iPlayerY;
		break;
	case 2:        /*向左移动*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY - 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY - 2;
		break;

	case 3:        /*向右移动*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY + 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY + 2;
		break;

	case 4:        /*向下移动*/
		iPlayerX1 = iPlayerX + 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX + 2;
		iPlayerY2 = iPlayerY;
		break;
	default:
		break;
	}
	/*对地图的操作*/
	switch (valueMap[iPlayerX1][iPlayerY1])/*判断小人下一步要走的位置*/
	{
	case WALL:      /*下一位置是墙，不能移动*/
		break;
	case SPACE:     /*下一位置为墙内空地和下一位置为空目的地的情况相同处理*/
	case TARGET:
		valueMap[iPlayerX1][iPlayerY1] = PERSON;/*小人移动到下一位置*/
		if (valueMap2[iPlayerX][iPlayerY] == TARGET || valueMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*小人所在位置初始为空目的地或满目的地，小人移动后此处恢复为空目的地*/
			valueMap[iPlayerX][iPlayerY] = TARGET;
		else
			/*小人所在位置初始为墙内空地、箱子或者小人，小人移动后此处恢复为墙内空地*/
			valueMap[iPlayerX][iPlayerY] = SPACE;
		break;
	case BOX: /*下一位置是箱子和下一位置是已放箱子目的地的情况相同处理*/
	case TARGET_IN:
		if (valueMap[iPlayerX2][iPlayerY2] == TARGET)
		{
			/*下下位置为空目的地，箱子和小人一起移动，箱子落入目的地*/
			valueMap[iPlayerX2][iPlayerY2] = TARGET_IN;
			valueMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else if (valueMap[iPlayerX2][iPlayerY2] == SPACE)
		{
			/*下下位置为空地，箱子和小人一起移动，箱子落入空地*/
			valueMap[iPlayerX2][iPlayerY2] = BOX;
			valueMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else/*下下位置为墙、箱子或者满目的地，不能移动，直接退出*/
			break;
		if (valueMap2[iPlayerX][iPlayerY] == TARGET || valueMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*小人所在位置初始为空目的地或满目的地，小人移动后此处恢复为空目的地*/
			valueMap[iPlayerX][iPlayerY] = TARGET;
		else/*小人所在位置初始为墙内空地、箱子或者小人，小人移动后此处恢复为墙内空地*/
			valueMap[iPlayerX][iPlayerY] = SPACE;
		break;
	}
	synMap();
}


