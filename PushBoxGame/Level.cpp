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


void  SelectColor(int iColor)                  //��ɫ����
{
	HANDLE  hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));//�õ�����̨����豸�ľ��
	SetConsoleTextAttribute(hConsole, iColor);//���ÿ���̨�豸������
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
			if (map[i][j] == &target || map[i][j] == &targetIn) /*��¼���Ӹ���*/
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
	int iPlayerX1, iPlayerY1;        /*С����һ��Ҫ�ߵ�λ������*/
	int iPlayerX2, iPlayerY2;        /*С������һ��Ҫ�ߵ�λ������*/
	setPersonPos();
	int iPlayerX = person.getX(), iPlayerY = person.getY();
	switch (iSelect) {
	case 1:        /*�����ƶ�*/
		iPlayerX1 = iPlayerX - 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX - 2;
		iPlayerY2 = iPlayerY;
		break;
	case 2:        /*�����ƶ�*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY - 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY - 2;
		break;

	case 3:        /*�����ƶ�*/
		iPlayerX1 = iPlayerX;
		iPlayerY1 = iPlayerY + 1;
		iPlayerX2 = iPlayerX;
		iPlayerY2 = iPlayerY + 2;
		break;

	case 4:        /*�����ƶ�*/
		iPlayerX1 = iPlayerX + 1;
		iPlayerY1 = iPlayerY;
		iPlayerX2 = iPlayerX + 2;
		iPlayerY2 = iPlayerY;
		break;
	default:
		break;
	}
	/*�Ե�ͼ�Ĳ���*/
	switch (valueMap[iPlayerX1][iPlayerY1])/*�ж�С����һ��Ҫ�ߵ�λ��*/
	{
	case WALL:      /*��һλ����ǽ�������ƶ�*/
		break;
	case SPACE:     /*��һλ��Ϊǽ�ڿյغ���һλ��Ϊ��Ŀ�ĵص������ͬ����*/
	case TARGET:
		valueMap[iPlayerX1][iPlayerY1] = PERSON;/*С���ƶ�����һλ��*/
		if (valueMap2[iPlayerX][iPlayerY] == TARGET || valueMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			valueMap[iPlayerX][iPlayerY] = TARGET;
		else
			/*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			valueMap[iPlayerX][iPlayerY] = SPACE;
		break;
	case BOX: /*��һλ�������Ӻ���һλ�����ѷ�����Ŀ�ĵص������ͬ����*/
	case TARGET_IN:
		if (valueMap[iPlayerX2][iPlayerY2] == TARGET)
		{
			/*����λ��Ϊ��Ŀ�ĵأ����Ӻ�С��һ���ƶ�����������Ŀ�ĵ�*/
			valueMap[iPlayerX2][iPlayerY2] = TARGET_IN;
			valueMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else if (valueMap[iPlayerX2][iPlayerY2] == SPACE)
		{
			/*����λ��Ϊ�յأ����Ӻ�С��һ���ƶ�����������յ�*/
			valueMap[iPlayerX2][iPlayerY2] = BOX;
			valueMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else/*����λ��Ϊǽ�����ӻ�����Ŀ�ĵأ������ƶ���ֱ���˳�*/
			break;
		if (valueMap2[iPlayerX][iPlayerY] == TARGET || valueMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			valueMap[iPlayerX][iPlayerY] = TARGET;
		else/*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			valueMap[iPlayerX][iPlayerY] = SPACE;
		break;
	}
	synMap();
}


