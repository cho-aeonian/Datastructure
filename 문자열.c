#include <stdio.h>

void removeSpacesAndPrint(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];  // 공백이 아닌 문자일 경우 새로운 위치에 저장
        }
    }
    str[j] = '\0';  // 문자열의 끝을 나타내는 널 문자로 마무리

    printf("%s\n", str);  // 결과 문자열 출력
}

int main() {
    char str[101];

    fgets(str, sizeof(str), stdin);  // 공백이 포함된 문자열 입력 받음

    removeSpacesAndPrint(str);  // 공백 제거 후 출력

    return 0;
}