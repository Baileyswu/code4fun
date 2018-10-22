#include <stdio.h>
int main()
{
	int t,n,i,j,p[25],str[45];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
		p[0]=0,j=1,i=1;
		while(j<=2*n)
		{
			int k=1;
			if(p[i]-p[i-1]){
                for(;k++<=p[i]-p[i-1];j++)
                    str[j]=1;
                str[j++]=-1;}
			else
                str[j++]=-1;
			i++;
		}
		i=1;
		while(i<n){
		for(j=p[i];j<2*n;j++)
			if(str[j]==-1)
			{
				str[j]=0;
				int k=0;
				while(str[j]!=1&&j>=1)
					j--,k++;
				str[j]=0;
				printf("%d ",(k+1)/2);
				i++;
				break;
			}
		}
		printf("%d\n",n);
	}
	return 0;
}
