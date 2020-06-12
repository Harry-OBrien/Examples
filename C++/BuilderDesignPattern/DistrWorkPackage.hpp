//
//  DistrWorkPackage.hpp
//  Builder
//
//  Created by Harry O'Brien on 06/03/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#ifndef DistrWorkPackage_hpp
#define DistrWorkPackage_hpp

#include <stdio.h>
#include <iostream>

class DistrWorkPackage
{
public:
  DistrWorkPackage(char *type)
  {
    sprintf(_desc, "Distributed Work Package for: %s", type);
  }
  void setFile(char *f, char *v)
  {
    sprintf(_temp, "\n  File(%s): %s", f, v);
    strcat(_desc, _temp);
  }
  void setQueue(char *q, char *v)
  {
    sprintf(_temp, "\n  Queue(%s): %s", q, v);
    strcat(_desc, _temp);
  }
  void setPathway(char *p, char *v)
  {
    sprintf(_temp, "\n  Pathway(%s): %s", p, v);
    strcat(_desc, _temp);
  }
  const char *getState()
  {
    return _desc;
  }
private:
  char _desc[200], _temp[80];
};

#endif /* DistrWorkPackage_hpp */
