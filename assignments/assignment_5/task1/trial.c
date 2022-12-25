#include <stdio.h>
#include <string.h>

char buffer[7];

int main(){
	/*
	printf("%d\n%d\n", sizeof(buffer), strlen(buffer));
	buffer[0] = 'a';
	buffer[1] = '\0';
	printf("%d\n%d\n", sizeof(buffer), strlen(buffer));
	buffer[1] = 'b';
	printf("%d\n", strlen(buffer));
	buffer[2] = '\0';
	printf("%d\n", strlen(buffer));
	buffer[1] = "";
	printf("%d\n", strlen(buffer));
	buffer[2] = 'c';
	printf("%s\n", buffer);
	printf("%d\n", strlen(buffer));
	buffer[1] = 'b';
	printf("%s\n", buffer);
	printf("%d\n", strlen(buffer));
	printf("%c %c\n", buffer[0], buffer[2]);
	*/

	buffer[5] = '';
	printf("%s -> %d\n", buffer, strlen(buffer));
}
