#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *getStr(int charCount){
	
        //Create space for chars -> +1 character for null byte
        char *string = malloc((sizeof(char) * charCount) + 1);

        //add 'r' number of 'A's to address at the string variable on head
        int i;
        for(i = 0; i < charCount; i++){
                strcat(string, "A");
        }

	return string;
}

int main(){

        //Generate a random number between 0 and 19
        srand(time(NULL));
        int r = rand() % 20;
        printf("Going to save %d to 'A's int memory this time!\n", r);

	char *res = getStr(r);

	//print string, then free up memory alloc
	puts(res);
	free(res);

	return 0;
}
