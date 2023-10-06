#include <stdio.h>
int main() {
	int a;
	scanf("%d", &a);
	
	int num[a];
	for(int i = 0; i < a; i++) {
		scanf("%d", &num[i]);
	}

	for(int i=0; i<a; i++){
			printf("%d: ",i+1);
		for (int j = 0; j < a; j++) {
			if (i != j) {
				if (num[i] < num[j])
					printf("< ");
				else if (num[i] > num[j])
					printf("> ");
				else
					printf("= ");
			}
			}
			printf("\n");
		}
		
		return 0;
}