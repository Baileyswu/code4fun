#include <stdio.h>
#define range 1299711
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
	set();
	int x, i;
	while(scanf("%d", &x) && x)
	{
		if(IsPrime[x])
			printf("0\n");
		else
		{
			int front, tail;
			for(i = x - 1;i > 1;i--)
				if(IsPrime[i])
				{
					front = i;
					break;
				}
			for(i = x + 1;i < range+1;i++)
				if(IsPrime[i])
				{
					tail = i;
					break;
				}
			printf("%d\n", tail - front);
		}
	}
	return 0;
}