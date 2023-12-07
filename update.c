#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void normalUpdate(){
	//setuid(geteuid());
	system("sudo apt-get update -y && sudo apt update -y && sudo apt upgrade -y");
}

void fullUpgrade(){
	//setuid(geteuid());
	system("sudo apt-get update -y && sudo apt update -y && sudo apt upgrade -y && sudo apt full-upgrade");
}


int main(void){
	int selection;
	while(selection != 1 &&  selection != 2){
	puts("Enter 1 to update\nEnter 2 for full OS upgrade");
	scanf("%d", &selection);
	}
	
	switch(selection)
	{
	case 1:
		puts("Standard update chosen\n");
		normalUpdate();
		break;
	case 2:
		puts("Full OS upgrade chosen\n");
		fullUpgrade();
		break;
	default:
		puts("Undefined error, please try again");
	
	}
	return 0;
}
