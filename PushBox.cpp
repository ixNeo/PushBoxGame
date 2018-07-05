#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
#include "PushBox.h"


using namespace std;

const int KEY_UP = 72;
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;

PushBox::PushBox() {
	//int **map[4];
	//map[0] = (int**)aiMap1;
	//map[1] = (int**)aiMap2;
	//map[2] = (int**)aiMap3;
	//map[3] = (int**)aiMap4;
	//for (int i = 0; i < 4; i++) {
	//	level[i] = Level(i, map[i]);
	//}
	int i = 0;
	level[i] = Level(i + 1, aiMap1);
}

void PushBox::play(int id) {
	char cOp;
	system("cls");
	level[id].printMap();
	if (level[id].tellIsWin()) {
		cout << " Congratulations" << endl;
		Sleep(3000);
		return ;
	}
	else {
		cOp = getch();          /*捕获用户键盘输入*/
		if ((cOp == 'n') || (cOp == 'N'))/*输入N进入下一关*/
			return play(id+1);
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

void PushBox::designUI() {
	int iCh;
	char cNum;
	iCh = welcomePage();
	if (iCh == 49)/*键盘输入1，开始第一关游戏*/
		play(0);
	else if (iCh == 50) {/*键盘输入2，选择1到4关的游戏*/
		cout << "\n\t\t Please input level!(From 1 to 4):";
		getchar();
		cNum = getchar();
		switch (cNum) {
		case '1':
		case '2':
		case '3':
		case '4':
			play(cNum-1);
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

int PushBox::welcomePage()
{
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

