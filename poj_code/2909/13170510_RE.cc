#include <stdio.h>
#include <string.h>
#define range 16400
bool IsPrime[range+1];
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
    return 0;
}
int main()
{
	int n, count;
	set();
	while(scanf("%d", &n) && n)
	{
		count = 0;
		for(int i = 2;i <= n/2;i++)
			if(IsPrime[i] && IsPrime[n - i])
				count++;
		printf("%d\n", count);
	}
	return 0;
}