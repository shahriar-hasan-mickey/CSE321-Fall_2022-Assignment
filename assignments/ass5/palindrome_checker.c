#include <stdio.h>
#include <string.h>

int main(){
	char string[50];
	scanf("%s", string);
	int i = 0;
	while(string[i] == string[strlen(string)-1-i] && i < (strlen(string)/2)) {
		i+=1;
	}
	if(i == strlen(string)/2)
		printf("Palindrome\n");
	else
		printf("Not Palindrome\n");

	return 0;

}
