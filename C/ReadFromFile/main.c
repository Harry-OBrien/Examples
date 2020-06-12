//
//  main.c
//  ReadFile
//
//  Created by Harry O'Brien on 27/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char data[60];
  
  FILE *file = fopen("myFile","r");
  
  fgets(data, sizeof data, file);
  if (strlen (data) > 0) {
    if (data[strlen (data) - 1] == '\n') {
      data[strlen (data) - 1] = '\0';
      printf("Your file contains: %s\n", data);
    } else {
      printf("%s\n", "Input too long!");
    }
  }
  
  fclose(file);
  return(0);
}
