//
//  main.cpp
//  Inheritance
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

/*
 A derived class inherits all base class methods with the following exceptions:
 - Constructors, destructors
 - Overloaded operators
 - The friend functions
*/

#include <iostream>

//Mother (parent) class
class Mother {
public:
  Mother (int setA){
    std::cout << "Mother ctor\n";
    a = setA;
  };
  
  ~Mother (){
    std::cout << "Mother dtor\n";
  }
  
protected:
  int a;
};

//Daughter class (of mother)
class Daughter : public Mother {
public:
  Daughter(int setA, int setB) : Mother(setA) {
    std::cout << "Daughter ctor\n";
    b = setB;
  };
  
  ~Daughter(){
    std::cout << "Daughter dtor\n";
  }
  
  void sayHi(){
    std::cout << a << " " << b << std::endl;
  }
  
private:
  int b;
};

//Main program call
int main(int argc, const char * argv[]) {
  Daughter d(5, 6);
  d.sayHi();
  
  return 0;
}
