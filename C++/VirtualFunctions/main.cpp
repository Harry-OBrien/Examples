//
//  main.cpp
//  Virtual Functions
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

//Virtual functions allow us to use e1->attack()
//Virtual is essentially a template for a function

#include <iostream>
using namespace std;

//Enemy (Parent)
class Enemy {
public:
  virtual void attack() {
  }
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
  e2->attack();
  
  return 0;
}
