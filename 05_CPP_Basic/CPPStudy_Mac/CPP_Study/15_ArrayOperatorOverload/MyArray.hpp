//
//  MyArray.hpp
//  15_ArrayOperatorOverload
//
//  Created by marker on 2019/6/1.
//  Copyright © 2019年 majortom. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <stdio.h>

class MyArray{
public:
    MyArray(int);
    MyArray(const MyArray &);
    ~MyArray();
    
    int GetData(int);
    void SetData(int,int);
    int Length();
    
    MyArray & operator = (const MyArray &);
    int & operator [](int);
    bool operator ==(const MyArray &);
    bool operator !=(const MyArray &);
private:
    int length;
    int *space;
};

#endif /* MyArray_hpp */
