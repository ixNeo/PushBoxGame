#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
using namespace std;
#include "PushBox.h"

const int KEY_UP = 72;  // �����
const int KEY_DOWN = 80;
const int KEY_LEFT = 75;
const int KEY_RIGHT = 77;

extern void  SelectColor(int iColor);

PushBox::PushBox() {
	this->level[0] = Level(0, aiMap1); // �ĸ��ؿ��ĳ�ʼ��
	this->level[1] = Level(1, aiMap2);
	this->level[2] = Level(2, aiMap3);
	this->level[3] = Level(3, aiMap4);
}

void PushBox::play(int id) {  // ��Ϸ��ˣ�Ŀ��ƺ�����ѡ�������һ���ؿ�������������ȣ����Ե����ƶ����Ӻ���
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
			cOp = _getch();          /*�����û���������*/
			if ((cOp == 'n') || (cOp == 'N'))/*����N������һ��*/
				if (id < 3)
					return play(id + 1);
				else
					return ;
			else if ((cOp == 'q') || (cOp == 'Q'))/*����Q����������*/
				return ;
		}
		switch (cOp)
		{          /*�û����뷽���*/
		case KEY_UP:        /*�ϼ�ͷ*/
			level[id].moveBox(1);
			break;
		case KEY_LEFT:        /*���ͷ*/
			level[id].moveBox(2);
			break;
		case KEY_RIGHT:        /*�Ҽ�ͷ*/
			level[id].moveBox(3);
			break;
		case KEY_DOWN:        /*�¼�ͷ*/
			level[id].moveBox(4);
			break;
		default:
			break;
		}
	}
}


void PushBox::initMap() {  // ��ʼ���ؿ��е��������ݣ��൱����������
	this->level[0] = Level(0, aiMap1);
	this->level[1] = Level(1, aiMap2);
	this->level[2] = Level(2, aiMap3);
	this->level[3] = Level(3, aiMap4);
}

int PushBox::welcomePage()  // ��ӭ����
{
	initMap();
	int i = 0;
	system("cls");/*����*/
	system("color 0E");/*������ɫ*/
	cout << "\n\n\t\t Welcome to play box!\n" << endl;
	cout << "\t\t Person:��  Wall:�� Box: ��  Target:��  Reach target����" << endl;
	cout << "\t\t Up:��\n\t\t Down:��\n\t\t Left:�� \n\t\t Right:��\n" << endl;
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

void PushBox::designUI() {  // �õ���ӭ��������룬������һ������ʼ��Ϸ������ѡ��ؿ��������˳���Ϸ��
	int iCh;
	char cNum;
	iCh = welcomePage();
	if (iCh == 49)/*��������1����ʼ��һ����Ϸ*/
	{
		getchar();
		play(0);
	}
	else if (iCh == 50) {/*��������2��ѡ��1��4�ص���Ϸ*/
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
	else if (iCh == 51) {/*��������3���˳���Ϸ*/
		system("cls");
		exit(0);
	}	
}



