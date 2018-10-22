#include <stdio.h>
#include <string.h>
int main()
{
	int t;
	scanf("%d", &t);
	char a[100], b[100];
	int na[100], nb[100], la, lb, m;
	for(int k = 0;k < t;k++)
	{
		scanf("%s%s", &a, &b);
		printf("%d ", k+1);
		la = strlen(a), lb = strlen(b);
		memset(na, 0, sizeof(na));
		memset(nb, 0, sizeof(nb));
		for(int i = 0;i < la;i++)na[i] = a[la-1-i]-'0';
		for(int j = 0;j < lb;j++)nb[j] = b[lb-1-j]-'0';
		if(la > lb)m = la;else m = lb;
		for(int i = 0;i < m;i++)
		{
			na[i] += nb[i];
			if(na[i] > 1 && i < m-1)
				na[i+1] += na[i]/2, na[i] %= 2;
		}
		while(na[m-1] > 1)
		{
			na[m] = na[m-1]/2;
			na[m-1] %= 2;
			m++;
		}
		while(!na[m-1] && m > 1)m--;
		for(int i = 0;i < m;i++)printf("%d", na[m-1-i]);
		printf("\n");
	}
	return 0;
}