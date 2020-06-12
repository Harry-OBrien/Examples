//
//  main.cpp
//  Pure Virtual Functions
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

//if

#include <iostream>
using namespace std;

//Enemy (Parent)
class Enemy {
public:
  virtual void attack() = 0; //The = 0 tells the compiler that the function has no body.
};

//Ninja
class Ninja: public Enemy {
public:
  void attack() {
    cout << "Ninja!"<<endl;
  }
};

//Monster
class Monster: public Enemy {
public:
  void attack() {
    cout << "Monster!"<<endl;
  }
};

int main(int argc, const char * argv[]) {
  
  Ninja n;
  Monster m;
  
  Enemy *e1 = &n;
  Enemy *e2 = &m;
  
  e1->attack();
  // Outputs "Ninja!"
  
  e2->attack();
  // Outputs "Monster!"
  
  return 0;
}
