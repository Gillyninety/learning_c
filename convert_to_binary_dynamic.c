//simple program to take positive decimal value and print the binary equivalent
//with memory dynamically allocated and the result printed in 4-byte increments

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int input = 0;

	puts("Enter a positive number");
	if(scanf("%d", &input)!=1){
		puts("Please enter a valid number");
		return 1;
		}
	
	if (input < 0){
	puts("Input out of range");
	return 1;}
	
	long long int bits = 1;
	while ((1 << bits) - 1 < input) {
        bits++;
	}
	
	bits = (bits + 3) & ~3;
	
	char* result = malloc(bits + 1);
	for(int i = 0; i < bits; i++)
	{
	result[i] = '0';
	}
	result[bits] = '\0';

	int save = input;

    	long long int i = bits - 1;
    	while (input > 0) {
        result[i--] = (input % 2) + '0';
        input /= 2;
    	}
	
	printf("The binary equivalent of %d in binary is: %s\n", save, result);
	free(result);
	result = NULL;
	return 0;
}
