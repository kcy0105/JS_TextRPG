#include <iostream>
#include "CMainGame.h"

using namespace std;

int main()
{
	std::srand((unsigned int)time(nullptr));

	CMainGame MainGame;

	MainGame.Initialize();
	MainGame.Update();

	return 0;
}