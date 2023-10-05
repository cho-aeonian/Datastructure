#include <stdio.h>
int main() {
	int a[100];
	int num, size = 0;
	
	while(1){
		scanf("%d", &num);
		if (num == 0)
			break;
		a[size] = num;
		size++;
	}
	
	for (int i = size - 1; i >= 0; i--) {
		printf("%d ", a[i]);
	}
	return 0;
}