#include <stdio.h>
int main()
{
	int num;
	scanf("%d", &num);
	
	while (num--) {
		int score = 0;  // 총 점수
		int now = 0;  // 현재 문제의 점수
		char test[81];
		scanf("%s", test);
		
		for (int i = 0; i < strlen(test); i++) {
			if (test[i] == 'O') {
				now++;
				score += now;
			}
			else
				now = 0;
		}
		printf("%d\n", score);
	}
	
	return 0;
}