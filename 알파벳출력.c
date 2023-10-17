#include <stdio.h>
#include <ctype.h>

#define ALPHABET_COUNT 26

int main() {
    char word[1000001];
    int count[ALPHABET_COUNT] = {0};
    int maxCount = 0;
    char maxChar = '?';

    // 단어 입력 받기
    scanf("%s", word);

    // 대소문자 구분 없이 알파벳 빈도수 세기
    for (int i = 0; word[i] != '\0'; i++) {
        char c = tolower(word[i]);
        if (isalpha(c)) {
            count[c - 'a']++;
            if (count[c - 'a'] > maxCount) {
                maxCount = count[c - 'a'];
                maxChar = toupper(c);
            } else if (count[c - 'a'] == maxCount) {
                maxChar = '?';
            }
        }
    }

    // 결과 출력
    printf("%c\n", maxChar);

    return 0;
}