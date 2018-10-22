#include <stdio.h>
#define N 500000
int flag[N*10] = {0};
int ans[N*10] = {0};
int main()
{
	int i, k;
	flag[0] = 1;
	for(i = 1;i < N+1;i++)
	{
		ans[i] = ans[i - 1] - i;
		if(ans[i] < 0 || flag[ans[i]] == 1)
			ans[i] = ans[i - 1] + i;
		flag[ans[i]] = 1;
	}
	while(scanf("%d", &k))
	{
		if(k == -1)
			break;
		printf("%d\n", ans[k]);
	}
	return 0;
}
