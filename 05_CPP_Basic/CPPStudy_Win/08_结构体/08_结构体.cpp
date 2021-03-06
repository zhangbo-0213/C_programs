// 08_结构体.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

struct EnemyPos {
	float posX;
	float posY;
	float posZ;
};

struct Enemy {
	string name;
	float hp;
	float attack;
	EnemyPos pos;
};

int main()
{
	EnemyPos pos1 = {100,20,30};
	pos1.posZ = 50;

	cout << "PosX:" << pos1.posX << "	PosZ:" << pos1.posZ << endl;

	Enemy enemy1 = { "MajorTom",100,50,{80,40,50} };

	cout << enemy1.name << "  " << enemy1.hp << "  " << enemy1.attack << "  " << "PosX:" << enemy1.pos.posX << "	PosY:" << enemy1.pos.posY << "  PosZ:" << enemy1.pos.posZ << endl;
    return 0;
}

