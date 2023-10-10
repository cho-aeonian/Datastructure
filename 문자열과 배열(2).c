#include <stdio.h>
int main(void) {
  char s[10], c;
  int i=0, p=-1 ;
 // 1. 문자열을 문자 배열에 입력 받기
   //2. 찾는 문자를 문자변수에 입력받기
   //3. 문자배열을 0번째 요소부터 탐색 
        //3.찾는 문자와 일치하면, 몇번째인지 저장
 scanf("%s", s);
   getchar();
   scanf("%c", &c);
   while(s[i] != '\0') {
   //4. 결과 출력
     if(s[i] == c) printf("%d번째\n", i+1);
     i++;
   }
  return 0;
}