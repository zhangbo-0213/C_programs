#include "stdafx.h"
#include "Hero.h"


Hero::Hero()
{
}

Hero::Hero(int hp, int demage):Human(hp,demage)
{
}

void Hero::Skill()
{
	cout << "Hero ÊÍ·Å¼¼ÄÜ" << endl;
}


Hero::~Hero()
{
}
