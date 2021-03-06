// 12_指针.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"

using namespace std;


int main()
{
	int a = 123;
	int* pointerA = &a;

	cout << "address:" <<pointerA <<"  value:"<<*pointerA <<endl;

	*pointerA = 234;

	cout << "address:" << pointerA <<"  value:"<< *pointerA << endl;

	// void 类型指针，可以接收任意类型的指针赋值，使用时需先进行类型明确
	int b = 55555;
	string str = "this is string";

	void* voidPointer;
	voidPointer = &str;
	voidPointer = &b;
	cout << "address of str:" << &str << endl;
	cout << "the value of voidPointer point at :" << *(int*)voidPointer <<endl;

	//NULL 空赋值，变量使用前需要赋值
	int* pointerB = NULL;
	pointerB = &b;

	//指针类型变量 int* 与引用类型变量 int& 
	int c = 100;
	int d = 200;
	int* cP = &c;
	int& dr = d;
	cout << "cp address:" << cP << endl;
	cout << "dr address:" << &dr << endl;

	//同：指针类型变量 * 与 引用类型变量 & 都可以对指向地址存储的数据修改
	//异：指针类型变量可以指向不同的地址，而引用类型的变量只能指向既定地址

	*cP = 300;
	dr = 400;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;

    return 0;
}

