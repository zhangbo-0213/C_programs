// 02_数据类型.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
int main()
{
	//cout << 100 << endl;
	//cout << 1.1 << endl;
	//cout << 'a' << endl;
	//cout << "C++ Study" << endl;

	int age = 100;
	float f = 1.23;

	cout << age + ':' + f << endl;

	string name = "majorTom";

	//endl表示换行，不能单独在行首；
	cout << name << endl;
    return 0;
}

