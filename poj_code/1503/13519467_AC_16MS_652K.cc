#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	char a[105],b[105];
	int x[105],y[105],xl,yl,i,j,l;
	scanf("%s",a);
	if(strcmp(a,"0")==0)
	{
		printf("0\n");
		return 0;
	}
	scanf("%s",b);
	if(strcmp(b,"0")==0)
	{
		printf("%s\n",a);
		return 0;
	}
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	xl=strlen(a);
	for(i=0;i<xl;i++)
		x[i]=a[xl-1-i]-'0';
	l=xl;
	while(1)
	{
		yl=strlen(b);
		for(j=0;j<yl;j++)
			y[j]=b[yl-1-j]-'0';
		l=max(l,yl);
		for(i=xl;i<l;i++)
			x[i]=0;
		for(j=yl;j<l;j++)
			y[i]=0;
		for(i=0;i<l;i++)
		{
			x[i]+=y[i];
			if(x[i] > 9)
			{
				if(i==l-1)
				{
					x[i+1]=0;
					l++;
					xl=l;
				}
				x[i+1]++;
				x[i]-=10;
			}
		}
		scanf("%s",b);
		if(strcmp(b,"0")==0)
			break;
	}
	for(i=l-1;i >=0;i--)
		printf("%d",x[i]);
	printf("\n");
	return 0;
}