//
//  Circle.cpp
//  07_ClassDevide
//
//  Created by marker on 2019/4/27.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Circle.hpp"
void Circle::Setpoint(int x, int y){
    point.SetPoint(x, y);
};

void Circle::SetRadius(int r){
    radius=r;
};

Point Circle::GetPoint(){
    return point;
};

int Circle::GetRadius(){
    return radius;
}

int Circle::TwoCirclelocation(Circle circle){
    //圆心距离大于半径之和，两圆相离
    if(point.DistanceTwoPoint(circle.GetPoint().GetPoint())>GetRadius()+circle.GetRadius()){
        return 1;
    }
    //圆心距离等于半径之和，两圆相切
    else if(point.DistanceTwoPoint(circle.GetPoint().GetPoint())==GetRadius()+circle.GetRadius()){
        return 0;
    }
    //否则两圆相交
    else{
        return -1;
    }
};
