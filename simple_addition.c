#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int result = 0;
    
	if (argc > 1){
		for (int i = 0; i < argc ; i++) {

		int x = strtol(argv[i], NULL, 10);
		result = result + x;
		}
	printf("The sum of your numbers is: %d\n", result);
	}
	else {
		puts("Provide numbers to add");
	}
return 0;
}

