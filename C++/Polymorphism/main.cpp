//
//  main.cpp
//  Polymorphism
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <iostream>
using namespace std;

//Parent enemy class
class Enemy {
protected:
  int attackPower;
public:
  void setAttackPower(int a){
    attackPower = a;
  }
};

//ninja class
class Ninja: public Enemy {
public:
  void attack(){
    cout << "Ninja - " << attackPower << endl;
  }
};

//Monster class
class Monster: public Enemy {
public:
   void attack(){
    cout << "Monster - " << attackPower << endl;
  }
};

int main(int argc, const char * argv[]) {

  Ninja n;
  Monster m;
  
  //Ninja and Monster inherit from Enemy, so all Ninja and Monster objects are Enemy objects.
  //This allows us to do the following:
  Enemy *e1 = &n;
  Enemy *e2 = &m;
  
  //set powers
  e1->setAttackPower(20);
  e2->setAttackPower(80);
  
  //attack!
  n.attack();
  m.attack();
  
  return 0;
}
