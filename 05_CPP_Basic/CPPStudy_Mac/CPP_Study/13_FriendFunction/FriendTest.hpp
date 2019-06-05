//
//  FriendTest.hpp
//  13_FriendFunction
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef FriendTest_hpp
#define FriendTest_hpp

#include <stdio.h>
class FriendTest{
public:
    FriendTest(int,int);
    // 友元函数声明
    friend void ModifyValue(FriendTest *F,int,int);
    //友元类声明
    friend class FriendTest2;
    void PrintValue();
private:
    int a;
    int b;
};

//友元类可以访问l元类中的所有成员
class FriendTest2{
public:
    FriendTest2(int,int);
    ~FriendTest2();
    void Print();
    void SetValue(int a,int b);
private:
    FriendTest *friendTest;
};
#endif /* FriendTest_hpp */
