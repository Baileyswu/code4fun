#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int cmp(char x, char y)
{
	return x < y;
}
int main()
{
	char a[105], b[105];
	while(~scanf("%s%s", a, b))
	{
		int la = strlen(a), lb = strlen(b);
		if(la != lb)
		{
			printf("NO\n");
			continue;
		}
		for(int i = 0;i < la;i++)
		{
			if(a[i] > 'A' && a[i] <= 'Z')
				a[i] -= 1;
			else if(a[i] == 'A')
				a[i] = 'Z';
		}
		sort(a, a+la, cmp);
		sort(b, b+la, cmp);
		if(strcmp(a, b))
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}