#include<stdio.h>
int n,k,m;
int f[10000];
int main(){
	f[0]=f[1]=0;
	while(~scanf("%d%d%d",&n,&k,&m))
	{
		for(int i = 2;i <= n-1;i++)
		{
			f[i]=(f[i-1]+k)%i;
		}
		f[n]=(f[n-1]+m)%n;
		printf("%d\n",f[n]+1);
	}
	return 0;
}