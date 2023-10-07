#include <stdio.h>
int main() {
	int num[9];
	int a = 0, b = -1;
	
	for (int i = 0; i < 9; i++) {
		scanf("%d", &num[i]);

		if (num[i] > a) {
			a = num[i];
			b = i;
		}
	}

	printf("%d\n", a);
	printf("%d\n", b + 1);

	return 0;
}