//
//  main.cpp
//  15_ArrayOperatorOverload
//
//  Created by marker on 2019/6/1.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    
    MyArray a1(10);
    for(int i=0;i<a1.Length();i++){
        //a1.SetData(i, i);
        a1[i]=i;
    }
    for(int i=0;i<a1.Length();i++){
//        cout<<"Array A1 Value:"<<a1.GetData(i)<<endl;
        cout<<"Array A1 Value:"<<a1[i]<<endl;
    }
    
    MyArray a2(5);
    for(int i=0;i<a2.Length();i++){
        //a1.SetData(i,i);
        a1[i]=i;
    }
    
    cout<<"a1==a2 :"<<(a1==a2)<<endl;
    cout<<"a1!=a2 :"<<(a1!=a2)<<endl;
    
    MyArray a3(a2);
    a3=a2=a1;
    for(int i=0;i<a3.Length();i++){
//        cout<<"Array A3 Value:"<<a3.GetData(i)<<endl;
        cout<<"Array A3 Value:"<<a3[i]<<endl;
    }
    return 0;
}
