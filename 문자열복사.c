#include <stdio.h>

void mystrcpy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {   // 원본 문자열의 끝까지 반복
        dest[i] = src[i];   // 원본 문자열의 각 문자를 대상 문자열로 복사
        i++;
    }
    dest[i] = '\0';   // 대상 문자열의 끝에 널 종료문자 추가
}

void mystrcpy2(char* dest, const char* src) {
   while (*src != '\0') {   // 원본 문자열의 끝까지 반복
       *dest = *src;   // 원본 문자열의 각 문자를 대상 문자열로 복사
       dest++;
       src++;
   }
   
   *dest = '\0';   // 대상 문자열의 끝에 널 종료문자 추가
}

int main() {
    char input[256];     // 입력받은 원본 문자열을 저장할 배열
    char copied1[256];   // mystrcpy 함수로 복사된 결과를 저장할 배열
    char copied2[256];   // mystrcpy2 함수로 복사된 결과를 저장할 배열

    fgets(input, sizeof(input), stdin);  // 사용자로부터 한 줄을 입력받아 input 배열에 저장

    mystrcpy(copied1, input);  // 입력받은 원본 문자열을 copied1 배열에 복사 (mystrcpy 함수 사용)
    
    mystrcpy2(copied2, input);  // 입력받은 원본 문잘ㄹ 을 copied2 배열에 복사 (mystrcpoy2 함수 사용)

    printf("%s\n", copied1);  // copied1 배열 출력
    
    printf("%s", copied2);  // copied2 배열 출력

    return 0;
}