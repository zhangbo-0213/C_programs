// 06_函数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

//函数提前声明
void CreateEnemy(int num);

int main()
{
	CreateEnemy(5);
    return 0;
}

//完成对应声明函数的实现
void CreateEnemy(int num) {
	for (int count = 0; count < num; count++) {
		cout << "创造一个敌人" << endl;
	}
}

