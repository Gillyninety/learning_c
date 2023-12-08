//simple program to take positive decimal value and print the binary equivalent 
//I did 4 bits for conciseness

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	char result[] = "0000";
	int input = 0;
	
	puts("Enter decimal number between 0 and 15");
	scanf("%d", &input);
	
	if (input > 15 || input < 0){
	puts("Stop being a tart");
	return 0;}

	while(input !=0){
	if((input - 8) >= 0){
		input = input - 8;
		result[0] = '1';
		}
	if((input - 4) >= 0){
		input = input - 4;
		result[1] = '1';
		}
	if((input - 2) >= 0){
		input = input - 2;
		result[2] = '1';
		}	
	if((input - 1) >= 0){
		input = input - 1;
		result[3] = '1';
		}	
	}
	
	printf("The binary equivalent of your number is: %s\n", result);
	return 0;
}
