// 07_字符串.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"

using namespace std;

int main()
{
	string str = "Stay Hungry,Stay Foolish";
	char b = str[5];
	//cout << b << endl;

	//字符串中的字符遍历
	//for (char c : str) {
	//	cout << c << " ";
	//}

	for (auto c : str) {
		cout << c << " ";
	}

	//字符大小写判断
	//char c = 'c';
	//cout << "字符是否为大小写："<<islower(c) << endl;

	//字符大小写转换
	char c = 'C';
	//cout << (char)tolower(c) << endl;

	//cin在接受输入时，会通过空格分割输入的内容
	//string name1;
	//string name2;
	//cin >>name1;
	//cin >> name2;
	//cout << "你输入的内容是：" << name1 << name2 << endl;

	//string l;
	//getline(cin,l);
	//cout << "你输入的内容是："<<l << endl;
    return 0;
}

