#include<stdio.h>
int arr[201][201]={0};
int main(){
	int i, j, k, l, n, m, num=1;
	scanf("%d %d",&n, &m);
	k=2;//k= i+j의 값
  
	//배열의 인덱스 위치에 값을 저장 코드 작성
	for(i=0;i<n+m-1;i++)
	{
		for(j=n;j>0;j--){
			for(l=1;l<=m;l++){
				if(j+l==k)
				{
					arr[j][l]=num;
					num++;
					
				}
			}
		}
		k++;
	}
	
	// 배열의 s결과를 출력
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}