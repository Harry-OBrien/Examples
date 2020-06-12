//
//  Reader.hpp
//  Builder
//
//  Created by Harry O'Brien on 06/03/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include <stdio.h>
#include "Builder.hpp"
#include "PersistenceAttribute.hpp"

class Reader
{
public:
  void setBuilder(Builder *b)
  {
    _builder = b;
  }
  void construct(PersistenceAttribute list[], int num)
  {
    for (int i = 0; i < num; i++)
      if (list[i].type == File)
        _builder->configureFile(list[i].value);
      else if (list[i].type == Queue)
        _builder->configureQueue(list[i].value);
      else if (list[i].type == Pathway)
        _builder->configurePathway(list[i].value);
  }
private:
  Builder *_builder;
};

#endif /* Reader_hpp */
