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
	cout << "Hero �ͷż���" << endl;
}


Hero::~Hero()
{
}
