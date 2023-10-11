#include <stdio.h>
#include <ctype.h>

int myStrlen(char str[]);       // 문자 전체의 길이
int myStrlen2(char str[]);      // 숫자의 길이
int myStrlen3(char str[]);      // 공백 제외 문자 길이
int myStrlen4(char str[], char c); // 특정 문자의 길이

int main() {
    char s[100];
    scanf("%s", s);

    printf("%d\n", myStrlen(s));   // 문자 전체의 길이
    printf("%d\n", myStrlen2(s));  // 숫자의 길이
    printf("%d\n", myStrlen3(s));  // 공백 제외 문자 길이
    printf("%d\n", myStrlen4(s, 'H')); // 특정 문자의 길이

    return 0;
}

int myStrlen(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int myStrlen2(char str[]) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            length++;
        }
    }
    return length;
}

int myStrlen3(char str[]) {
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace(str[i])) {
            length++;
        }
    }
    return length;
}

int myStrlen4(char str[], char c) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}