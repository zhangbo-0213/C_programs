// 13_类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Human.h"
#include "Hero.h"

int main()
{
	Human human=Human(100,50);
	cout << human.GetHP() << endl;
	human.Attack();
	human.TakeDemage(30);

	Human human1 = Human();
	cout << human1.GetHP() << endl;
	human1.TakeDemage(30); 

	Hero hero = Hero(500,300);
	cout << "Hero Hp" << endl;
	cout << hero.GetHP() << endl;
	hero.Skill();
	
	system("pause");
    return 0;
}

