//5개 문자형 원소를 입력 받아 역순으로 출력해보자.
//순서대로 출력한 다음 수정하여 작성해 보자.
#include <stdio.h>
int main(){
	char a[5];
	int i;
	for(i=0; i<5; i++){
		scanf("%c",&a[i]);
		getchar();
	}
	for(i=4; i>=0; i--){
		printf("%c",a[i]);
	}
	
	return 0;
}