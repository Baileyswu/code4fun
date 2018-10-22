#include<stdio.h>
int main()
{
	int a,b,x,y,we,i,j,re;
	while(scanf("%d%d",&a,&b)!=EOF)
{	re=0;
	x=a,y=b;
	a=(x<y)?x:y;
	b=(x>y)?x:y;
	for(i=0;i<b-a+1;i++)
	{	we=i+a;
		j=1;
		while(we!=1)
		{if(we%2) we=3*we+1;
		else we=we/2;
		j++;}
		we=j;
		if(we>re) re=we;
	}
	printf("%d %d %d\n",x,y,re);
}
	return 0;
}