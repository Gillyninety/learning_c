// Program to update linux system through apt. Written for kali, but should work for anything Debian-based

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void checkPrivs(){
	if (getuid() != 0) {
	puts("Please run as sudo or root.");
	exit(0);
	}
}

void normalUpdate(){
	//setuid(geteuid());
	system("apt-get update -y && apt update -y && apt upgrade -y");
}

void fullUpgrade(){
	//setuid(geteuid());
	system("apt-get update -y && apt update -y && apt upgrade -y && apt full-upgrade -y");
}


int main(void){
	checkPrivs();
	
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
