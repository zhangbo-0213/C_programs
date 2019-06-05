//
//  FriendTest.cpp
//  13_FriendFunction
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "FriendTest.hpp"
#include <iostream>

using namespace std;

FriendTest::FriendTest(int _a,int _b){
    this->a=_a;
    this->b=_b;
}

void FriendTest::PrintValue(){
    cout<<"a:"<<this->a<<endl;
    cout<<"b:"<<this->b<<endl;
}

FriendTest2::FriendTest2(int a,int b){
    friendTest=new FriendTest(a,b);
}

FriendTest2::~FriendTest2(){
    delete friendTest;
}

void FriendTest2::Print(){
    friendTest->PrintValue();
}

void FriendTest2::SetValue(int a, int b){
    friendTest->a=a;
    friendTest->b=b;
    Print();
}
