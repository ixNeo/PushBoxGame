#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
using namespace std;
#include "PushBox.h"

const int KEY_UP = 72;  // 方向键
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;

extern void  SelectColor(int iColor);

PushBox::PushBox() {
	this->level[0] = Level(0, aiMap1); // 四个关卡的初始化
	this->level[1] = Level(1, aiMap2);
	this->level[2] = Level(2, aiMap3);
	this->level[3] = Level(3, aiMap4);
}

void PushBox::play(int id) {  // 游戏玩耍的控制函数，选择进入下一个关卡，返回主界面等，可以调用移动箱子函数
	char cOp;
	while(1){
		system("cls");
		level[id].printMap();
		cout << "sum" << level[id].getBoxSum() << endl;
		cout << "findsum" << level[id].getFindBoxSum() << endl;
		if (level[id].tellIsWin()) {
			cout << " Congratulations" << endl;
			Sleep(3000);
			if (id < 3)
				return play(id + 1);
			else
				return;
		}
		else {
			cOp = _getch();          /*捕获用户键盘输入*/
			if ((cOp == 'n') || (cOp == 'N'))/*输入N进入下一关*/
				if (id < 3)
					return play(id + 1);
				else
					return ;
			else if ((cOp == 'q') || (cOp == 'Q'))/*输入Q返回主界面*/
				return ;
		}
		switch (cOp)
		{          /*用户输入方向键*/
		case KEY_UP:        /*上箭头*/
			level[id].moveBox(1);
			break;
		case KEY_LEFT:        /*左箭头*/
			level[id].moveBox(2);
			break;
		case KEY_RIGHT:        /*右箭头*/
			level[id].moveBox(3);
			break;
		case KEY_DOWN:        /*下箭头*/
			level[id].moveBox(4);
			break;
		default:
			break;
		}
	}
}


void PushBox::initMap() {  // 初始化关卡中的所有内容，相当于重新启动
	this->level[0] = Level(0, aiMap1);
	this->level[1] = Level(1, aiMap2);
	this->level[2] = Level(2, aiMap3);
	this->level[3] = Level(3, aiMap4);
}

int PushBox::welcomePage()  // 欢迎界面
{
	initMap();
	int i = 0;
	system("cls");/*清屏*/
	system("color 0E");/*设置颜色*/
	cout << "\n\n\t\t Welcome to play box!\n" << endl;
	cout << "\t\t Person:♀  Wall:▓ Box: ●  Target:○  Reach target：☆" << endl;
	cout << "\t\t Up:↑\n\t\t Down:↓\n\t\t Left:← \n\t\t Right:→\n" << endl;
	cout << "\t\t Press number 1 to start new game\n\t\t" << endl;
	cout << "\t\t Press number 2 to choose level\n\t\t" << endl;
	cout << "\t\t Press number 3 to quit from game\n\t\t" << endl;
	cout << "\t\t Press right number to continue:";
	while (1)
	{
		i = getchar();
		if (i >= 49 && i <= 51)
			return i;
	}
}

void PushBox::designUI() {  // 得到欢迎界面的输入，进行下一步（开始游戏，或者选择关卡，或者退出游戏）
	int iCh;
	char cNum;
	iCh = welcomePage();
	if (iCh == 49)/*键盘输入1，开始第一关游戏*/
	{
		getchar();
		play(0);
	}
	else if (iCh == 50) {/*键盘输入2，选择1到4关的游戏*/
		cout << "\n\t\t Please input level!(From 1 to 4):";
		
		getchar();
		cNum = getchar();
		switch (cNum) {
		case '1':
		case '2':
		case '3':
		case '4':
			play((int)cNum-49);
			break;
		default:
			cout << "Enter error!" << endl;
			Sleep(1000);
			exit(0);
			break;
		}
	}
	else if (iCh == 51) {/*键盘输入3，退出游戏*/
		system("cls");
		exit(0);
	}	
}



