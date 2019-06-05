//
//  Array.cpp
//  12_ClassArrayCustom
//
//  Created by marker on 2019/5/11.
//  Copyright © 2019年 majortom. All rights reserved.
//

#include "Array.hpp"
#include <iostream>

using namespace std;
Array::Array(int count){
    cout<<"Constructor Function Called"<<endl;
    this->array=new int[count];
    this->length=count;
}

Array::Array(const Array & array){
    cout<<"Copy Constructor Function Called"<<endl;
    this->array=new int[array.length];
    if(this->array!=NULL){
        this->length=array.length;
        for(int i=0;i<this->length;i++){
            this->array[i]=array.array[i];
        }
    }
    
}

void Array::SetData(int index, int value){
    this->array[index]=value;
}

int Array::GetData(int index){
    return this->array[index];
}

int Array::GetLength(){
    return length;
}
Array::~Array(){
    delete [] array;
    cout<<"Discontructor Function Called"<<endl;
}
