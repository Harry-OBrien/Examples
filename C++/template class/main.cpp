//
//  main.cpp
//  template class
//
//  Created by Harry O'Brien on 15/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <iostream>

template <class T>
class Pair {
private:
  T first, second;
  
public:
  Pair(T a, T b):
  first(a),second(b){
    
  }
  T bigger();
};

//Class Constructor
template <class T>
T Pair<T>::bigger(){
  return (first > second ? first : second);
}

int main(int argc, const char * argv[]) {
  
  //define class of type int and double
  Pair <int> i(2, 12);
  Pair <double> d(23.45, 5.67);
  
  std::cout << i.bigger() << std::endl;
  std::cout << d.bigger() << std::endl;
  
  return 0;
}
