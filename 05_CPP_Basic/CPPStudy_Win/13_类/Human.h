#pragma once
class Human
{
//public:
//	Human();
//	~Human();

public:	
	void Attack();
	void TakeDemage(int demage);
	Human(int hp,int demage);//带参构造函数定义
	Human();//无参构造函数定义
	int GetHP();
	int GetDemage();
private:
	int HP;
	int Demage;
};

