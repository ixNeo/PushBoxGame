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
	int valueMap[14][16]; // ���ݵ�ͼ�����㴦��
	int valueMap2[14][16]; // ���ݵ�ͼ�������������ƶ���ĸ��µ�ͼ��������
	int boxSum;  // ��������
	int findBoxSum;  // �Ѿ��ҵ���������Ŀ

public:
	// ĳһ���͵ļ�����
	Box box = Box(); Wall wall = Wall(); Person person = Person(); 
	Space space = Space(); SpaceOut spaceOut = SpaceOut(); Target target = Target(); TargetIn targetIn = TargetIn();
	Element* map[14][16];  // ��ʵ�洢���͵ĵ�ͼ
	Level() {}
	Level(int id, int valueMap[14][16]);
	
	int getId() {
		return id;
	}

	//Element* getMap() {
	//	return map;
	//}

	Level operator = (Level a); // ���
	int getBoxSum();  // �õ���������
	int getFindBoxSum();// �õ��ɹ���������
	void printMap(); // ���ݵ�ͼ��ӡ����
	void moveBox(int direction);  // �ƶ�����
	void setPersonPos();  // ������������
	void synMap();  // ͬ�����ݵ�ͼ����ʵ��ͼ
	bool tellIsWin();  // �ж��Ƿ�ʤ��
};

