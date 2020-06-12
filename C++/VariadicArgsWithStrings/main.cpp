//
//  main.cpp
//  VariadicArgsWithStrings
//
//  Created by Harry O'Brien on 26/04/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <iostream>

namespace SDL_HAL {

  #define panic(...) printStrings((const char*[]){__VA_ARGS__, NULL})

  void printStrings(const char** str) {
    while(*str) printf("Error: %s\n", *str++);
  }

}
int main(int argc, const char * argv[]) {
  SDL_HAL::panic("run while you can!",
        "something is horribly wrong",
        "oh god!"
        );
  return 0;
}
