#include <stdio.h>

int main(){
	int a, b, result;
	scanf("%d %d", &a, &b);
	if(a > b)
		result = a-b;
	else if(a < b)
		result = a+b;
	else
		result = a*b;
	printf("%d\n", result);
	return 0;
}
