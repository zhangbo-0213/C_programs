#pragma once
class Human
{
//public:
//	Human();
//	~Human();

public:	
	void Attack();
	void TakeDemage(int demage);
	Human(int hp,int demage);//���ι��캯������
	Human();//�޲ι��캯������
	int GetHP();
	int GetDemage();
private:
	int HP;
	int Demage;
};

