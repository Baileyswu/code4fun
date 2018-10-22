#include <stdio.h>
#include <string.h>
#define N 301
int n, count;
bool colm[N], set1[2*N + 1], set2[2*N];
int dfs(int x)
{
	int i, p;
	if(x == n + 1)
		return 1;
    for(i = 1;i <= n;i++)
    {
    	if(!colm[i] && !set1[x + i] && !set2[x - i + n])
    	{
    		colm[i] = 1;
    		set1[x + i] = 1;
    		set2[x - i + n] = 1;
    		p = dfs(x + 1);
    		if(p)
    		{
    			count++;
    			printf("%d ", i);
    			return 1;
    		}
    		colm[i] = 0;
    		set1[x + i] = 0;
    		set2[x - i + n] = 0;
    	}
    }
    return 0;
}
int main()
{
    while(~scanf("%d", &n))
    {
    	memset(colm, 0, sizeof(colm));
    	memset(set1, 0, sizeof(set1));
    	memset(set2, 0, sizeof(set2));
        dfs(1);
        printf("\n");
    }
    return 0;
}