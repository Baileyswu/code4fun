#include<stdio.h>
int cow[103][2010];
int main()
{
	int C,F1,F2,D;
	int i,j,count,first,final;
	while((scanf("%d%d%d%d",&C,&F1,&F2,&D))!=EOF)
	{
		count=0;
		for(i=1;i<=C;i++)
		{
			scanf("%d%d",&first,&final);
			for(j=first;j<=final;j++)
				cow[i][j]=1;	
		}
		for(j=D;;j--)
		{
			for(i=1;i<=C;i++)
				if(cow[i][j]==1)
				count++;
				if(count==F1-F2)
					break; 
		}
		printf("%d\n",j);
	} 
	return 0;
} 