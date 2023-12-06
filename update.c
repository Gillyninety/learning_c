#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	//setuid(geteuid());
	system("sudo apt-get update -y && sudo apt update -y && sudo apt upgrade -y");
}

