//
//  PersistenceAttribute.hpp
//  Builder
//
//  Created by Harry O'Brien on 06/03/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#ifndef PersistenceAttribute_hpp
#define PersistenceAttribute_hpp

enum PersistenceType
{
  File, Queue, Pathway
};

struct PersistenceAttribute
{
  PersistenceType type;
  char value[30];
};

#endif /* PersistenceAttribute_hpp */
