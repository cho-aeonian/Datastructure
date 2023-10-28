#include <stdio.h>
#include <math.h>
#define N 5

typedef struct point {
    int x, y;
} POINT;

void inputPoint(POINT *p);
void outputPoint(POINT *p);
double distance(POINT *p, POINT *q);

int main() {
    POINT p[N];
    POINT origin = {0, 0};
    
    // 좌표 입력
    for (int i = 0; i < N; i++) {
        inputPoint(&p[i]);
    }

    POINT closest_point = p[0]; // 가장 가까운 좌표를 일단 첫 번째 좌표로 설정
    double min_distance = distance(&origin, &p[0]); // 최소 거리를 첫 번째 좌표와의 거리로 초기화

    // 나머지 좌표들과의 거리를 비교하여 가장 가까운 좌표를 찾음
    for (int i = 1; i < N; i++) {
        double current_distance = distance(&origin, &p[i]);
        if (current_distance < min_distance || 
            (current_distance == min_distance && p[i].x + p[i].y < closest_point.x + closest_point.y)) {
            min_distance = current_distance;
            closest_point = p[i];
        }
    }

    printf("원점에서 가장 가까운 좌표 : ");
    outputPoint(&closest_point);

    return 0;
}

void inputPoint(POINT *p) {
    scanf("%d %d", &(p->x), &(p->y));
}

void outputPoint(POINT *p) {
    printf("(  %d,   %d)\n", p->x, p->y);
}

double distance(POINT *p, POINT *q) {
    return sqrt((p->x - q->x) * (p->x - q->x) + (p->y - q->y) * (p->y - q->y));
}