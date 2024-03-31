// The idea is to create a sign up/sign in program in C then to alter it to use C++ later in an effort to 
// become more familiar with both. 
// THIS DOES NOT WORK, IS NOT MEMORY SAFE, AND SHOULD NOT BE USED
// It is purely for reference and educational purposes
// don't forgot to add -lcrypto to gcc

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <openssl/sha.h>

void clearBuffer() {
    int x;
    while ((x = getchar()) != '\n');
}

void login(){

}


char* encrypt(char clearText[]){
    size_t length = strlen(clearText);    
    char encText[SHA_DIGEST_LENGTH];
    SHA1(clearText, length, encText);
    return encText;
}


int readFromFile(){

    return 0;
}


int writeToFile(char fileName[], char* username, char* password){
    FILE *fp = fopen(fileName, "a+");
    if((fp == NULL)) {return(-1);}
    fprintf(fp, "<%s> %s\n", username, password);
    fclose(fp);	    
    return 0;
}

int fileContains(char* username_input){
    FILE *fp = fopen(fileName, "r");
    if((fp == NULL)) {return(-1);}
    
}

int sanitiseUsername(char* username_input){
    puts("Enter username:");
    scanf("%s", username_input);
//need to fix later with ability to accept spaces
    int x = sizeof(username_input);
    if(fileContains(username_input)){
      printf("Username \"%s\" is already taken.\n", username_input);
      return 1;
    }
    for(int i = 0; i < x; i++){
      	if(username_input[i] == '<' || username_input[i] == '>'){
      	  printf("Invalid character \"%c\" used\n", username_input[i]);
      	  return 1;
      	  } 
      	if(isspace(username_input[i]) != 0){
      	  puts("Invalid character \"space\" used\n");
 	  return 1;
      	} else {
          return 0;  
        }
    }   
}

int sanitisePassword(char* password_input){
    //more needed here
    puts("Enter password:");
    scanf("%s", password_input);
    if (sizeof(password_input) < 8){
      puts("Password length must be at least 8 digits");
      return 1;
    }
    return 0;
}

int reg(){
    int input;
    puts("Welcome!\n \nPress 1 to register a new account. \nPress 2 to return.\n");
    while(scanf("%d", &input)!= 1 || input > 2 || input < 1){
        puts("Please enter a valid choice");
        clearBuffer();
    }
    switch(input) {
    case 1:
      char username_input[] = "Default";
      while(sanitiseUsername(username_input) != 0);
      char* username = username_input;
      char password_input[] = "Default";
      while(sanitisePassword(password_input) != 0);
      char* password = password_input;
      char* hashed_password = encrypt(password);
      if (writeToFile("files/users.txt", username, hashed_password) != 0){
      	        puts("Error saving user");
      	        exit(1);
      	        }
    case 2:
      return 0;
      break;
    default: puts("Error");
    }
}


void mainMenu(){
    while(1){
    system("clear");
    
    int input;
    
    puts("Main menu:\n \nWelcome!\n \nPress 1 to log in. \nPress 2 to register. \nPress 3 to exit.\n");
    while(scanf("%d", &input)!= 1 || input > 3 || input < 1){
        puts("Please enter a valid choice");
        clearBuffer();
    }
    switch(input) {
    case 1:
      login();
      break;
    case 2:
      reg();
      break;
    case 3:
      puts("Exiting...");
      exit(0);
      break;
    default: puts("Error");
	}
    }
}

void main(void){
	reg();
}


