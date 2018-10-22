#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	char s1[105], s2[105];
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s%s", s1, s2);
		int l1 = strlen(s1), l2 = strlen(s2), p = 0;
		for(int i = 0;i < l1;i++)
			if(s1[i] == s2[p])
				p++;
		if(p == l2)
			printf("YES\n");
		else
		{
			p = l2 - 1;
			for(int i = 0;i < l1;i++)
				if(s1[i] == s2[p])
					p--;
			if(p == -1)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}