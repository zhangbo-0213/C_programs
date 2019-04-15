#include "stdafx.h"
#include "Human.h"


//Human::Human()
//{
//}
//
//
//Human::~Human()
//{
//}

//带参构造函数实现
Human::Human(int hp,int demage) {
	HP = hp;
	Demage = demage;
}

//无参构造函数实现
Human::Human() {
	HP = 1000;
	Demage = 100;
}

void Human::Attack()
{
	cout << "播放攻击动作" << endl;
	cout << "播放攻击特效" << endl;
	cout << "造成对方伤害" << endl;
}

void Human::TakeDemage(int demage)
{
	cout<<"播放受伤动作"<<endl;
	cout <<"播放受伤特效"<< endl;
	HP -= demage;
	cout<<"当前生命值："<<HP<<endl;
}

int Human::GetHP() {
	return HP;
}

int Human::GetDemage() {
	return Demage;
}
