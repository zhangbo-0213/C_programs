// 09_随机数.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "time.h"

using namespace std;


int main()
{
	srand((int)time(0));
	cout << "猜数字 1-10" << endl;
	int num = rand() % 10 + 1;
	int num1;
	while (true)
	{
		cout << "你的答案是？" << endl;
		cin >> num1;
		if (num1 == num) {
			cout << "猜对了，结束游戏"<<endl;
			break;
		}
		else {
			cout << "继续猜呀" << endl;
		}
	}
    return 0;
}

