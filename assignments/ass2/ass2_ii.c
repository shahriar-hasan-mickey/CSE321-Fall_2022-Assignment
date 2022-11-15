#include <stdio.h>
#include <stdlib.h>
int main() {
	char a[50];
	fgets(&a, "%c", stdin);
	printf("%s", a);
	return 0;
}
