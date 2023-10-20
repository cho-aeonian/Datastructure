#include <stdio.h>
int arr[201][201] = {0}; // 2차원 배열 arr를 선언하고 0으로 초기화함. 최대 크기는 201x201임.

int main() {
   int i, j, k, l, n, m, num = 1; // 변수 선언

   scanf("%d %d", &n, &m); // 두 개의 정수 값을 입력받아 n과 m에 저장

   k = 2; // k는 i와 j의 합, k를 2로 초기화

   // 배열의 인덱스 위치에 값을 저장하는 코드 작성
   for(i = 0; i < n + m - 1; i++) { // 첫번째 for문: i를 0부터 n+m-2까지 반복
         for(j = n; j > 0; j--) { // 두번째 for문 1: j를 n부터 1까지 역순으로 반복
               for(l = 1; l <= m; l++) { // 세번째 for문 2: l을 1부터 m까지 반복합니다.
                     if(j + l == k) { // j와 l의 합이 k와 같다면
                           arr[j][l] = num; // 배열 arr의 위치에 num 값을 저장
                           num++; // num값을 1 증가
                        }
                  }
            }
         k++; // k 값을 증가
      }

   // 배열의 결과를 출력
   for (i = 1; i <= n; i++) { // 첫번째 for문: i를 1부터 n까지 반복
         for (j = 1; j <= m; j++) { // 두번째 for문: j를 1부터 m까지 반복
               printf("%d ", arr[i][j]); // 배열 arr의 해당 위치값을 출력
            }
         printf("\n"); // 행을 출력한 후 줄 바꿈을 수행하여 다음 행을 출력
      }
   return 0;
}