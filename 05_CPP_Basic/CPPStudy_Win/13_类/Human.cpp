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

//���ι��캯��ʵ��
Human::Human(int hp,int demage) {
	HP = hp;
	Demage = demage;
}

//�޲ι��캯��ʵ��
Human::Human() {
	HP = 1000;
	Demage = 100;
}

void Human::Attack()
{
	cout << "���Ź�������" << endl;
	cout << "���Ź�����Ч" << endl;
	cout << "��ɶԷ��˺�" << endl;
}

void Human::TakeDemage(int demage)
{
	cout<<"�������˶���"<<endl;
	cout <<"����������Ч"<< endl;
	HP -= demage;
	cout<<"��ǰ����ֵ��"<<HP<<endl;
}

int Human::GetHP() {
	return HP;
}

int Human::GetDemage() {
	return Demage;
}
