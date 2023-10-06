#include <stdio.h>
int main() {
	int N, M;
	scanf("%d", &N);

	int num[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	scanf("%d", &M);
	
	for (int i = 0; i < M; i++) {
		int a, b = 0;
		scanf("%d", &a);
		
		for (int j = 0; j < N; j++) {
			if (num[j] == a) {
				b = 1;
				break;
			}
		}
		
		printf("%d ", b);
	}
	
	return 0;
}