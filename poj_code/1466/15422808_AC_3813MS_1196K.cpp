#include "stdio.h"
#include "string.h"
#define M 520
int g[M][M];
int link[M];
int used[M];
int n;
int dfs(int stu)
{
	int i;
    for( i=0;i<n;i++)
    if(!used[i]&&g[stu][i])
	   {
		   used[i]=1;
		   if(link[i]==-1||dfs(link[i]))
		   {
		   link[i]=stu;
		   return 1;
		   }
	   }
	   return 0;
}
int main()
{
	int m;
	int a,b,i,j,l,ans;
	while(scanf("%d",&n)!=EOF)
	{
		memset(g,0,sizeof(g));
		memset(link,-1,sizeof(link));
		for(i=0;i<n;i++)
		{
			scanf("%d: (%d)",&a,&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&b);
				g[a][b]=1;
			}
		}
		ans=0;
		for(l=0;l<n;l++)
		{
			memset(used,0,sizeof(used));
			if(dfs(l))ans++;
		}
		if(ans%2)
		ans+=1;
		printf("%d\n",n-ans/2);
	}
	return 1;
}