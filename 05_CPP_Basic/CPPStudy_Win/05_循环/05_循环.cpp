// 05_循环.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int count = 0;
	while (true) {
		cout << "生成一个敌人" << endl;
		count++;
		if (count >=10)
			break;
	}
    return 0;
}

