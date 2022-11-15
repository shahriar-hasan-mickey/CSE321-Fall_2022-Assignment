#include <stdio.h>
#include <string.h>
int main(){
	char email[50], checker[10];
	strcpy(checker, "sheba.xyz");
	scanf("%s", email);
	email[strlen(email)] = '\0';

	int i = 0;
	while(email[i] != '@') i+=1;
	i+=1;
	int j = i;
	while(email[i] == checker[i-j] && i < strlen(email)) {
//printf("%d %c %c \n", i, email[i], checker[i-j]);
		i+=1;
	}
	
	if(i==strlen(email))
		printf("Email address is okay\n");
	else
		printf("Email address is outdated\n");
	return 0;
	
}
