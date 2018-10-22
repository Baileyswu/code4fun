#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int cmp(int x, int y)
{
	return x > y;
}
int sm(int x, int y)
{
	return x < y;
}
int main()
{
	int t, p, i;
	char num[100], kil[100];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%s", &p, num);
		strcpy(kil, num);
		int len = strlen(num);
		sort(kil, kil+len, cmp);
		if(!strcmp(num, kil))
		{
			printf("%d BIGGEST\n", p);
			continue;
		}
		int q;
		for(i = len-1;i > 0;i--)
			if(num[i] > num[i-1])
			{
				q = i-1;
				break;
			}
		sort(num+q+1, num+len, sm);
		for(i = q+1;i < len;i++)
			if(num[i] > num[q])
				break;
		int t = num[i];
		num[i] = num[q];
		num[q] = t;
		sort(num+q+1, num+len, sm);
		printf("%d %s\n", p, num);
	}
	return 0;
}
