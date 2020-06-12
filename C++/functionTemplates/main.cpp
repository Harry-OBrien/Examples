//
//  main.cpp
//  functionTemplates
//
//  Created by Harry O'Brien on 15/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <iostream>

template <class T, class S>
T smaller (T a, S b){
  return (a < b ? a : b);
}

int main(int argc, const char * argv[]) {
  
  std::cout << smaller(39.334, 47) << std::endl;
  
  return 0;
}
