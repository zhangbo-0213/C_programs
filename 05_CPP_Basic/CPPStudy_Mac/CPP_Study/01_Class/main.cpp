//
//  main.cpp
//  CPP_Study
//
//  Created by marker on 2019/4/15.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
using namespace std;

class Circle{
public:
    double r;
    double pi=3.1415926;
    double area;
    
    double GetArea(){
        area=pi*r*r;
        return area;
    }
};

int main(int argc, const char * argv[]) {
    Circle c;
    cout<<"请输入半径"<<endl;
    cin>>c.r;
    cout<<"圆的半径是："<<c.GetArea()<<endl;

    return 0;
}
