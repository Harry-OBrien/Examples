//
//  main.c
//  VariadicArgsWithStrings
//
//  Created by Harry O'Brien on 26/04/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>

#define panic(...) printStrings((const char*[]){__VA_ARGS__, NULL})

void printStrings(const char** str) {
  while(*str) printf("Error: %s\n", *str++);
}

int main(int argc, const char * argv[]) {
  
  panic("run while you can!",
        "something is horribly wrong",
        "oh god!"
        );
  
  return 0;
}
