#include<stdio.h>
int main()
{
	int a[351][351],n,i,j,re;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			scanf("%d",&a[i][j]);
	a[1][0]+=a[0][0],a[1][1]+=a[0][0];
	for(i=2;i<n;i++)
	{
		a[i][0]+=a[i-1][0],a[i][i]+=a[i-1][i-1];
		for(j=1;j<i;j++)
			a[i][j]+=(a[i-1][j-1]>a[i-1][j])?a[i-1][j-1]:a[i-1][j];
	}
	re=a[n-1][0];
	for(i=1;i<n;i++)
		if(re<a[n-1][i])
			re=a[n-1][i];
	printf("%d",re);
	return 0;
}