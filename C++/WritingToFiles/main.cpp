//
//  main.cpp
//  WritingToFiles
//
//  Created by Harry O'Brien on 29/08/2018.
//  Copyright © 2018 DriftUK. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char *argv[])
{
  //  std::ofstream myFile;
  //  myFile.open("test.txt");
  //is equivilant to:
  std::ofstream myFile("test.txt");

  /*
   File Opening Modes
   
   ios::app     append to end of file
   ios::ate     go to end of file on opening
   ios::binary  open in binary mode
   ios::in      reading only
   ios::out     writing only
   ios::trunc   delete contents of the file if it exists
   
   all of the above can be used with the bitwise OR (|)
   eg: outfile.open("file.dat", std::ios::out | std::ios::trunc)
   
   */

  if (myFile.is_open())
    myFile << "Some Text.\n";

  else
    std::cout << "something went wrong" << std::endl;

  myFile.close();
  return 0;
}
