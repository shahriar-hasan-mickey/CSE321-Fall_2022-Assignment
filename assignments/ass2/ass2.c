#include <stdio.h>

int main() {
	char a[50];
	scanf("%[^\n]s", &a);
	printf("%s", a);
	return 0;
}
