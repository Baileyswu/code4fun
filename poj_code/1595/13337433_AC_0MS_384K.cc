#include <stdio.h>
#define range 1001
bool IsPrime[range+1];
int prime[170];
int axis[1001];
int set()
{
    int i,j;
    for(i=2;i<=range;i++)
        IsPrime[i]=true;
    IsPrime[0]=false;
    IsPrime[1]=false;
    for(i=2;i<=range;i++)
    {
        if(IsPrime[i])
        {
            for(j=2*i;j<=range;j+=i)
                IsPrime[j]=false;
        }
    }
    j = 2, prime[1] = 1, prime[170] = 1001;
    for(i = 2;i <= range;i++)
    	if(IsPrime[i])
    		prime[j++] = i;
    for(j = 1;j < 170;j++)
    	for(i = prime[j];i < prime[j+1] && i<= 1000;i++)
    		axis[i] = j;
    return 0;
}

int main()
{
	set();
	int n, c, i;
	while(~scanf("%d%d", &n, &c))
	{
		printf("%d %d:", n, c);
		if(axis[n] <= c * 2)
			for(i = 1;i <= axis[n];i++)
				printf(" %d", prime[i]);
		else
		{
			if(axis[n]&1LL)
				for(i = axis[n]/2+1-(c-1);i<=axis[n]/2+c;i++)
					printf(" %d", prime[i]);
			else
				for(i = axis[n]/2+1-c;i<=axis[n]/2+c;i++)
					printf(" %d", prime[i]);
		}
		printf("\n\n");
	}
	return 0;
}