// 03_输入输出.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "string"
using namespace std;

int main()
{
	cout << "请输入name:" << endl;
	string name;
	cin >> name;
	cout << "得到用户输入，name:" + name << endl;
    return 0;
}

