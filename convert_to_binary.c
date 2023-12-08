//simple program to take positive decimal value and print the binary equivalent 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	char result[] = "00000000";
	int input = 0;
	
	puts("Enter a number between 0 and 255");
	if(scanf("%d", &input)!=1){
		puts("Please enter a valid number");
		return 1;
		}
	
	if (input > 255 || input < 0){
	puts("Input out of range");
	return 0;}
	
	int save = input;

	for (int i = 0; i < 8; i++) {
        result[i] = '0';
    	}

    	int i = 7;
    	while (input > 0) {
        result[i--] = (input % 2) + '0';
        input /= 2;
    	}
	
	printf("The binary equivalent of %d in binary is: %s\n", save, result);
	return 0;
}
