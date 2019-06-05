//
//  main.cpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/24.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include <iostream>
#include "Student.hpp"
#include "Point.hpp"
#include "Circle.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Student student;
    student.SetAge(10);
    char name[20]="MajorTom";
    student.SetName(name);
    cout<<"Age: "<<student.GetAge()<<endl;
    cout<<"Name: "<<student.GetName()<<endl;
    
    int x1,y1,r1,x2,y2,r2;
    
    cout<<"请输入圆1的 圆心坐标 x:"<<endl;
    cin>>x1;
    cout<<"请输入圆1的 圆心坐标 y:"<<endl;
    cin>>y1;
    cout<<"请输入圆1的 半径 r:"<<endl;
    cin>>r1;
    
    Circle circle1;
    circle1.Setpoint(x1, y1);
    circle1.SetRadius(r1);
    cout<<"圆1的圆心坐标："<<circle1.GetPoint().GetPoint().x<<" "<<circle1.GetPoint().GetPoint().y<<endl;
    cout<<"圆1的半径： "<<circle1.GetRadius()<<endl;
    
    cout<<"请输入圆2的 圆心坐标 x:"<<endl;
    cin>>x2;
    cout<<"请输入圆2的 圆心坐标 y:"<<endl;
    cin>>y2;
    cout<<"请输入圆2的 半径 r:"<<endl;
    cin>>r2;
    Circle circle2;
    circle2.Setpoint(x2, y2);
    circle2.SetRadius(r2);
    cout<<"圆2的圆心坐标："<<circle2.GetPoint().GetPoint().x<<" "<<circle2.GetPoint().GetPoint().y<<endl;
    cout<<"圆2的半径： "<<circle2.GetRadius()<<endl;
    cout<<"两圆的位置关系："<<circle2.TwoCirclelocation(circle1)<<endl;
    
    
    return 0;
}
