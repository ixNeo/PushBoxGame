#include "Map.h"

const int SPACE_OUT = 0;
const int WALL = 1;
const int SPACE = 2;
const int TARGET = 3;
const int BOX = 4;
const int TARGET_IN = 5;
const int PERSON = 6;

Map::Map(int** valueMap) {
	boxSum = 0;
	findBoxSum = 0;
	valueMap = valueMap;
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

int Map::getBoxSum() {
	for (int i = 0; i<14; i++)
		for (int j = 0; j<16; j++) {
			//valueMap[i][j] = valueMap[i][j];
			if (map[i][j] == &target || map[i][j] == targetIn) {/*��¼���Ӹ���*/
				boxSum++;
				if (map[i][j] == targetIn)
					findBoxSum++;
			}
		}
	return boxSum;
}

int Map::getFindBoxSum() {
	return findBoxSum;
}

void Map::printMap() {
	int i, j;
	for (i = 0; i<14; i++) {
		for (j = 0; j<16; j++)
		{
			map[i][j]->printElement();
			switch (aiMap[i][j])
			{
			case 0:                /*�յ�*/
				printf("  ");
				break;
			case 1:
				SelectColor(14);    /*ǽ*/
				printf("��");
				break;
			case 2:                /*�ڲ��յ�*/
				printf("  ");
				break;
			case 3:
				SelectColor(11);    /*Ŀ�ĵ�*/
				printf("��");
				break;
			case 4:                /*����*/
				SelectColor(11);
				printf("��");
				break;
			case 5:                /*�����Ƶ�Ŀ�ĵغ���ʾ*/
				SelectColor(9);
				printf("��");
				break;
			case 6:                /*С��*/
				SelectColor(10);
				printf("��");
				break;
			}
		}
		printf("\n");
	}
	SelectColor(14);
	printf("\n");
	printf("\tYou are in Level %d!\t\t\n", iImp);
	printf("\tPress arrow keys to play the game!\t\n");
	printf("\tpress N to the next level!\t\n");
	printf("\tpress Q to return the home page!\t\n");
}

void Map::moveBox(int iSelect) {
	int iPlayerX1, iPlayerY1;        /*С����һ��Ҫ�ߵ�λ������*/
	int iPlayerX2, iPlayerY2;        /*С������һ��Ҫ�ߵ�λ������*/
	setPersonPos();
	int iPlayerX = person.x, iPlayerY = person.y;
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
	switch (map[iPlayerX1][iPlayerY1])/*�ж�С����һ��Ҫ�ߵ�λ��*/
	{
	case WALL:      /*��һλ����ǽ�������ƶ�*/
		break;
	case SPACE:     /*��һλ��Ϊǽ�ڿյغ���һλ��Ϊ��Ŀ�ĵص������ͬ����*/
	case TARGET:
		map[iPlayerX1][iPlayerY1] = &PERSON;/*С���ƶ�����һλ��*/
		if (aiMap2[iPlayerX][iPlayerY] == &target || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else
			/*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	case BOX: /*��һλ�������Ӻ���һλ�����ѷ�����Ŀ�ĵص������ͬ����*/
	case TARGET_IN:
		if (aiMap[iPlayerX2][iPlayerY2] == TARGET)
		{
			/*����λ��Ϊ��Ŀ�ĵأ����Ӻ�С��һ���ƶ�����������Ŀ�ĵ�*/
			aiMap[iPlayerX2][iPlayerY2] = TARGET_IN;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else if (aiMap[iPlayerX2][iPlayerY2] == SPACE)
		{
			/*����λ��Ϊ�յأ����Ӻ�С��һ���ƶ�����������յ�*/
			aiMap[iPlayerX2][iPlayerY2] = BOX;
			aiMap[iPlayerX1][iPlayerY1] = PERSON;
		}
		else/*����λ��Ϊǽ�����ӻ�����Ŀ�ĵأ������ƶ���ֱ���˳�*/
			break;
		if (aiMap2[iPlayerX][iPlayerY] == TARGET || aiMap2[iPlayerX][iPlayerY] == TARGET_IN)
			/*С������λ�ó�ʼΪ��Ŀ�ĵػ���Ŀ�ĵأ�С���ƶ���˴��ָ�Ϊ��Ŀ�ĵ�*/
			aiMap[iPlayerX][iPlayerY] = TARGET;
		else/*С������λ�ó�ʼΪǽ�ڿյء����ӻ���С�ˣ�С���ƶ���˴��ָ�Ϊǽ�ڿյ�*/
			aiMap[iPlayerX][iPlayerY] = SPACE;
		break;
	}	
}

void Map::setPersonPos(){
	for (int i = 0; i<14; i++) {
		for (int j = 0; j < 16; j++) {
			if (map[i][j] == &person) {
				person.setXY(i, j);
			}
		}
	}
}