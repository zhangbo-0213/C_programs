// 04_运算符.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{

	int a = 100, b = 90;
	int res1 = a + b;
	int res2 = a - b;
	int res3 = a * b;
	int res4 = a / b;
	int res5 = a % b;
	cout << res1 <<"	"<< res2 << "    " << res3 << "    " << res4 << "    " << res5 << endl;
    
	int hp = 100;
	bool isDead = hp <= 0;
	cout << "角色死亡了吗？" << isDead << endl;
	
	return 0;
}

