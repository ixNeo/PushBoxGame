#pragma once
#include <conio.h>
#include <windows.h>
void  SelectColor(int iColor)                  //��ɫ����
{
	HANDLE  hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));//�õ�����̨����豸�ľ��
	SetConsoleTextAttribute(hConsole, iColor);//���ÿ���̨�豸������
}
