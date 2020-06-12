//
//  main.cpp
//  operatorOverloading
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

//overloading the '+' operator to add two objects together

#include <iostream>

class MyClass {
public:
  int var;
  MyClass(){
    
  }
  MyClass(int a):var(a){
    
  }
  
  MyClass operator+(MyClass &obj){
    MyClass res;
    res.var=this->var+obj.var;
    return res;
  }
  
};

int main(int argc, const char * argv[]) {

  MyClass obj1(12), obj2(55);
  MyClass res = obj1 + obj2;
  
  std::cout << res.var << std::endl;
  
  return 0;
}
