// 11_数组.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	//数组定义声明，在数组名后加[]
	int enemyArray[10];

	//数组未初始化
	//VC的DEBUG版会把未初始化的指针自动初始化为0xCCCCCCCC，而不是就让它随机去，那是因为DEBUG版的目的是为了方便我们调试程序
	//int：-858993460（十六进制OXCCCCCCCC）（二进制11001100110011001100110011001100）
	for (auto i : enemyArray) {
		cout << i << endl;
	}

	//数组进行部分初始化，未初始化的元素值默认为 0
	int array2[10] = {10,90,4,3,25,78,89};
	for (auto i : array2) {
		cout << i << endl;
	}
    return 0;
}

