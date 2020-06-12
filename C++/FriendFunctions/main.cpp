//
//  main.cpp
//  FriendFunctions
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

//Normally, private members of a class cannot be accessed from outside of that class.
//However, declaring a non-member function as a friend of a class allows it to access
//the class' private members. This is accomplished by including a declaration of this
//external function within the class, and preceding it with the keyword friend.

#include <iostream>

//The MyClass class
class MyClass {
public:
  MyClass(){
    regVar = 0;
  }
private:
  int regVar;
  
  friend void someFunc(MyClass &obj);
};

//note how this isn't part of the 'MyClass' class
void someFunc(MyClass &obj){
  std::cout << obj.regVar << std::endl;
  obj.regVar = 42;
  std::cout << obj.regVar << std::endl;
}

int main(int argc, const char * argv[]) {
 
  MyClass mc;
  someFunc(mc);
  
  return 0;
}
