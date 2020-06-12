//
//  main.cpp
//  ReadingFromFiles
//
//  Created by Harry O'Brien on 29/08/2018.
//  Copyright © 2018 DriftUK. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
  std::string line;
  std::ifstream myFile("test.txt");
  
  while(getline(myFile, line))
  {
    std::cout << line << std::endl;
  }
  
  myFile.close();
  
  return 0;
}
