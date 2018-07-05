#pragma once
#include "Level.h"
class PushBox {
private:
	Level level[4];

public:	
	int aiMap1[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 3, 4, 2, 1, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 3, 4, 6, 4, 2, 2, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 3, 2, 4, 2, 4, 3, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	int aiMap2[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 1, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 1, 1, 1, 2, 4, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 1, 3, 3, 3, 1, 2, 1, 0, 0, 0, 0 },
		{ 0, 0, 1, 1, 2, 1, 3, 3, 1, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 1, 2, 4, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0 },
		{ 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 6, 2, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	int aiMap3[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0 },
		{ 0, 0, 1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 0, 0 },
		{ 0, 0, 1, 2, 4, 2, 1, 1, 1, 1, 4, 2, 2, 1, 0, 0 },
		{ 0, 0, 1, 2, 2, 4, 3, 3, 3, 3, 2, 4, 2, 1, 0, 0 },
		{ 0, 0, 1, 1, 2, 2, 2, 2, 1, 2, 6, 2, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	int aiMap4[14][16] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 3, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 2, 2, 4, 3, 3, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 2, 2, 4, 2, 1, 5, 3, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 2, 1, 1, 4, 1, 2, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 4, 2, 2, 4, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 2, 2, 2, 1, 2, 2, 2, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 6, 2, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	};

	PushBox();

	int welcomePage();
	void designUI();
	void play(int id);
	
};