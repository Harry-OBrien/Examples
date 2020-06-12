//
//  main.cpp
//  Builder
//
//  Created by Harry O'Brien on 06/03/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

#include "Reader.hpp"
#include "DistrWorkPackage.hpp"
#include "Builder.hpp"
#include "PersistenceAttribute.hpp"

const int NUM_ENTRIES = 6;
PersistenceAttribute input[NUM_ENTRIES] =
{
  {
    File, "state.dat"
  }
  ,
  {
    File, "config.sys"
  }
  ,
  {
    Queue, "compute"
  }
  ,
  {
    Queue, "log"
  }
  ,
  {
    Pathway, "authentication"
  }
  ,
  {
    Pathway, "error processing"
  }
};

int main(int argc, char* argv[])
{
  UnixBuilder unixBuilder;
  VmsBuilder vmsBuilder;
  Reader reader;
  
  reader.setBuilder(&unixBuilder);
  reader.construct(input, NUM_ENTRIES);
  std::cout << unixBuilder.getResult()->getState() << std::endl;
  
  reader.setBuilder(&vmsBuilder);
  reader.construct(input, NUM_ENTRIES);
  std::cout << vmsBuilder.getResult()->getState() << std::endl;
}
