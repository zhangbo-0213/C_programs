// 10_枚举类型.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

enum WeekDay {
	Monday,Tuesday,Wednesday,Thursday,Saturday,Sunday
};

int main()
{
	WeekDay day = Wednesday;
	cout << day << endl;
    return 0;
}

