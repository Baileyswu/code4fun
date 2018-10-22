#include <stdio.h>
#include <string.h>
int main()
{
	int t, n, v;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		char pre[15], com[15];
		scanf("%s", pre);
		int l1 = strlen(pre), i;
		v = 0;
		n--;
		while(n--)
		{
			scanf("%s", com);
			if(v)
				continue;
			int l2 = strlen(com);
			if(l2 < l1)
				continue;
			for(i = 0;i < l1;i++)
				if(com[i]!=pre[i])
					break;
			if(i==l1)
			{
				printf("NO\n");
				v = 1;
			}
		}
		if(!v)
			printf("YES\n");
	}
	return 0;
}