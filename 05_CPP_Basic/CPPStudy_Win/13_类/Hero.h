#pragma once
#include "Human.h"
class Hero :public Human
{
public:
	Hero();
	Hero(int hp,int demage);
	void Skill();
	~Hero();
};

