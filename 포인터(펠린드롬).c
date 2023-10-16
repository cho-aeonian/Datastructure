#include <stdio.h>
#include <string.h>

int palindrome(char* str) {
    int length = strlen(str);  // 문자열의 길이를 구함
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // 펠린드롬이 아님
        }
    }

    return 1; // 펠린드롬임
}

int main() {
    char str[100];

    scanf("%s", str);  // 사용자로부터 문자열 입력 받음

    if (palindrome(str)) {  
        printf("Yes\n");  // 펠린드롬인 경우 "Yes" 출력
    } else {
        printf("No\n");   // 펠린드롬이 아닌 경우 "No" 출력
    }

    return 0;
}