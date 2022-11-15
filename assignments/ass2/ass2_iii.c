#include <stdio.h>

int main() {
	char a[50];
	fgets(a, "%s", stdin);
	printf("%s", a);
	return 0;
}
