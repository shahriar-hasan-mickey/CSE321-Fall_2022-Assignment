#include <stdio.h>
#include <string.h>

int main(){
	char passwd[100];
	scanf("%s", passwd);
//	char special[] = {'_', '@', '#', '$'};
	int special, digit, upper, lower;
	//printf("%d, %d, %d, %d\n", special, digit, upper, lower);
	special = digit = upper = lower = 0;
	for(int i = 0; i < strlen(passwd); i++){
		if(passwd[i] == '_' || passwd[i] == '#' || passwd[i] == '@' || passwd[i] == '$') special+=1;
		if(passwd[i] >= '0' && passwd[i] <= '9') digit+=1;
		if(passwd[i] >= 'a' && passwd[i] <= 'z') lower+=1;
		if(passwd[i] >= 'A' && passwd[i] <= 'Z') upper+=1;
	}
	
	// write the message appending each unfulfilled criteria
	char message[255];
	if(special==0 || digit==0 || upper==0 || lower==0){
		if(special==0) {
			if(strlen(message) == 0)
				strcpy(message, "Special character missing");	
			else 
				strcpy(message, ", Special character missing");
			printf("%s", message);
		}
		if(digit==0) {
			if(strlen(message) == 0)
				strcpy(message, "Digit missing");
			else
				strcpy(message, ", Digit missing");
			printf("%s", message);
		}
		if(upper==0) {
			if(strlen(message) == 0)
				strcpy(message, "Uppercase character missing");
			else
				strcpy(message, ", Uppercase character missing");
			printf("%s", message);
		}
		if(lower==0) {
			if(strlen(message) == 0)
				strcpy(message, "Lowercase character missing");
			else 
				strcpy(message, ", Lowercase character missing");
			printf("%s", message);
		}
	}else {
		strcpy(message, "OK");
		printf("%s", message);
	}

	//printf("s=%d d=%d u=%d l=%d\n", special, digit, upper, lower);
	printf("\n");
	return 0;
}
