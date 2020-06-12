//
//  main.cpp
//  Template Specialisation
//
//  Created by Harry O'Brien on 15/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <iostream>

template <class T>
class MyClass {
  
  
public:
  MyClass(T x){
    std::cout << x << " - not a char" << std::endl;
  }
};

template<>
class MyClass<char>{
  
public:
  MyClass(char x){
    std::cout << x << " - is a char" << std::endl;
  }
};

int main(int argc, const char * argv[]) {
 
	MyClass<int>(2);
	MyClass<char>('c');
  return 0;
}
