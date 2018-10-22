#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_ 100005
int num[max_], fin[max_];
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		for(int i = 1;i <= n;i++)
			scanf("%d", &num[i]);
		int v = 0;
		for(int i = 1;i <= n;i++)
			fin[num[i]] = i;
		for(int i = 1;i <= n;i++)
			if(fin[i] != num[i])
			{
				v = 1;
				break;
			}
		if(v)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
	}
	return 0;
}