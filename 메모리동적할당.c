#include <stdio.h>

int main() {
    int numPeople, height, maxHeight = -1; // 최대값을 음수로 초기화

    scanf("%d", &numPeople);

    if (numPeople < 1 || numPeople > 100) {
        return 1; // 프로그램 종료
    }

    for (int i = 0; i < numPeople; i++) {
        scanf("%d", &height);

        if (height < 0) {
            return 1; // 프로그램 종료
        }

        if (height > maxHeight) {
            maxHeight = height; // 최대값 업데이트
        }
    }

    printf("%d\n", maxHeight);

    return 0;
}