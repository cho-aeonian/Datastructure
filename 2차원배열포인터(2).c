#include <stdio.h>

void inputArray(int a[][4], int row);
int totArray(int *a, int size);

int main() {
    int score[3][4];
    int i, j, tot;
    double avg;

    // 점수 입력 함수 호출
    inputArray(score, 3);

    // 각 학생의 총점과 평균을 계산하여 출력
    for (i = 0; i < 3; i++) {
        tot = totArray(score[i], 4);  // 각 학생의 총점 계산
        avg = (double)tot / 4.0;  // 각 학생의 평균 계산
        printf("총점 : %d, 평균 : %.2lf\n", tot, avg);
    }

    return 0;
}

void inputArray(int a[][4], int row) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

int totArray(int *a, int size) {
    int i, tot = 0;
    for (i = 0; i < size; i++) {
        tot += a[i];
    }
    return tot;
}