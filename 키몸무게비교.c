#include <stdio.h>

// 학생 정보를 저장할 구조체 정의
typedef struct {
    int id;
    double height;
    double weight;
} Student;

int main() {
    int N;
    scanf("%d", &N);

    // 학생 정보를 저장할 배열 선언
    Student students[N];

    // 학생 정보 입력 받기
    for (int i = 0; i < N; i++) {
        scanf("%d%lf%lf", &students[i].id, &students[i].height, &students[i].weight);
    }

    // 키와 몸무게의 평균 계산
    double totalHeight = 0.0;
    double totalWeight = 0.0;

    for (int i = 0; i < N; i++) {
        totalHeight += students[i].height;
        totalWeight += students[i].weight;
    }

    double averageHeight = totalHeight / N;
    double averageWeight = totalWeight / N;

    printf("%.1lf %.1lf\n", averageHeight, averageWeight);

    // 각 학생의 키와 몸무게를 비교하여 출력
    for (int i = 0; i < N; i++) {
        if (students[i].height >= averageHeight && students[i].weight >= averageWeight) {
            printf("%d super\n", students[i].id);
        } else if (students[i].height >= averageHeight || students[i].weight >= averageWeight) {
            printf("%d average\n", students[i].id);
        } else {
            printf("%d below\n", students[i].id);
        }
    }

    return 0;
}