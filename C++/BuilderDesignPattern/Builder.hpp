//
//  Builder.hpp
//  Builder
//
//  Created by Harry O'Brien on 06/03/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#ifndef Builder_hpp
#define Builder_hpp

#include <stdio.h>
#include "DistrWorkPackage.hpp"

class Builder
{
public:
  virtual void configureFile(char*) = 0;
  virtual void configureQueue(char*) = 0;
  virtual void configurePathway(char*) = 0;
  DistrWorkPackage *getResult()
  {
    return _result;
  }
protected:
  DistrWorkPackage *_result;
};

class UnixBuilder: public Builder
{
public:
  UnixBuilder()
  {
    _result = new DistrWorkPackage("Unix");
  }
  void configureFile(char *name)
  {
    _result->setFile("flatFile", name);
  }
  void configureQueue(char *queue)
  {
    _result->setQueue("FIFO", queue);
  }
  void configurePathway(char *type)
  {
    _result->setPathway("thread", type);
  }
};

class VmsBuilder: public Builder
{
public:
  VmsBuilder()
  {
    _result = new DistrWorkPackage("Vms");
  }
  void configureFile(char *name)
  {
    _result->setFile("ISAM", name);
  }
  void configureQueue(char *queue)
  {
    _result->setQueue("priority", queue);
  }
  void configurePathway(char *type)
  {
    _result->setPathway("LWP", type);
  }
};

#endif /* Builder_hpp */
