#include <iostream>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <cstdlib>

#include "Element.h"
#include "Box.h"
#include "Person.h"
#include "Space.h"
#include "SpaceOut.h"
#include "Target.h"
#include "TargetIn.h"

#include "Level.h"
#include "PushBox.h"

using namespace std;

int main() {
	PushBox pushBox = PushBox();
	while (1)
		pushBox.designUI();
	return 0;
}