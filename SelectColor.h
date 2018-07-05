#pragma once
#include <conio.h>
#include <windows.h>
void  SelectColor(int iColor)                  //颜色函数
{
	HANDLE  hConsole =
		GetStdHandle((STD_OUTPUT_HANDLE));//得到控制台输出设备的句柄
	SetConsoleTextAttribute(hConsole, iColor);//设置控制台设备的属性
}
