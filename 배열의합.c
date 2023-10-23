#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	float enso[12][2] = { {1990, 0.6}, 
											  {1991, 0.2}, 
											  {1992, 1.1}, 
											  {1993, 0.5}, 
											  {1994, 0.1}, 
											  {1995, 1.2}, 
											  {1996, -0.3},
											  {1997, -0.1},
											  {1998, 2.2}, 
											  {1999, -0.7},
											  {2000, -1.1}     };
	float max=0.0,m=0.0;
	int i,j;
	printf("엘니뇨 : ");
	for(i=0;i<11;i++)
	{
		if(enso[i][1]>0.0)
		{
			if(enso[i][1]>max)
			{
				max=enso[i][1];
				m=enso[i][0];
			}
			printf("%.0f ",enso[i][0]);
		}
	}
	printf("\n가장 강한 엘니뇨 : %.0f\n",m);
	
	
	printf("라니냐 : ");
	for(i=0;i<11;i++)
	{
		if(enso[i][1]<0.0)
		{
			if(enso[i][1]<max)
			{
				max=enso[i][1];
				m=enso[i][0];
			}
			printf("%.0f ",enso[i][0]);
		}
	}
	printf("\n가장 강한 라니냐 : %.0f\n",m);
	
	printf("가장 정상적인 해 : ");
	max=100.0;
	for(i=0;i<11;i++)
	{
		if(fabs(enso[i][1])==max)
		{
			max=fabs(enso[i][1]);
			printf("%.0f ",m);
			m=enso[i][0];
			printf("%.0f ",m);
		}
		if(fabs(enso[i][1])<max)
		{
			max=fabs(enso[i][1]);
			m=enso[i][0];
		}
	}
	return 0;
}