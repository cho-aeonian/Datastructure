#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parseAndPrintNumbers(char* str) {
    char* token = strtok(str, ",");  // 쉼표를 기준으로 문자열을 분리하여 토큰으로 추출

    while (token != NULL) {
        printf("%s\n", token);  // 토큰을 정수로 변환하지 않고 그대로 출력
        token = strtok(NULL, ",");  // 다음 쉼표까지의 문자열을 토큰으로 추출
    }
}

int main() {
    char str[100];

    scanf("%s", str);  // 사용자로부터 문자열 입력 받음

    parseAndPrintNumbers(str);  // 입력된 문자열을 분리하여 숫자를 출력

    return 0;
}