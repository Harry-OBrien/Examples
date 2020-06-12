#include <stdio.h>
#include <string.h>

int main() {
   char line[60];

   puts("What is your name?");
   printf("%s", "> ");

   fgets(line, sizeof line, stdin);
   if (strlen (line) > 0) {
        if (line[strlen (line) - 1] == '\n') {
                line[strlen (line) - 1] = '\0';
                printf("Your name is: %s\n", line);
        } else {
                printf("%s\n", "Input too long!");
        }
   }
   return(0);
}
