#include <stdio.h>

int main() {
	char a[50];
	fgets(a, 50, stdin);
	char b[50];
	int j = 0;
	int space = 0;
	for(int i = 0; i < sizeof(a)-1; i++){
		if(a[i] != ' '){
			b[j] = a[i];
			j+=1;
			space = 0;
		} else if(a[i] == ' '){
			if(a[i+1] == ' '){
				space+=1;
				if(space==1){
					b[j] = a[i];
					j+=1;
				}
			}else{
				if(space==0){
					b[j] = a[i];
					j+=1;
				}
			}
			
		}

	}
	printf("%s", b);
	return 0;
}
