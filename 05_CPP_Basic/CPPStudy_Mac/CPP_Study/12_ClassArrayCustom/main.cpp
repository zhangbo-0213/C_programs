//
//  main.cpp
//  12_ClassArrayCustom
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Array.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    Array arr(10);
    for(int i=0;i<arr.GetLength();i++){
        arr.SetData(i, i);
    }
    for(int i=0;i<arr.GetLength();i++){
        cout<<"arr[i]="<<arr.GetData(i)<<endl;
    }
    
    Array arr2=arr;
    
    return 0;
}
