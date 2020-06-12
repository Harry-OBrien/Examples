//
//  main.cpp
//  this
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

//this is a pointer to the object, so the arrow selection operator is used to select the member variable.

#include <iostream>
using namespace std;

class MyClass {
public:
  MyClass(int a): var(a){
    
  }
  
  void printInfo(){
    cout << var << endl;
    cout << this->var << endl;
    cout << (*this).var << endl;
  }
  
private:
  int var;
};

int main(int argc, const char * argv[]) {

  MyClass obj(42);
  obj.printInfo();
  
  return 0;
}
