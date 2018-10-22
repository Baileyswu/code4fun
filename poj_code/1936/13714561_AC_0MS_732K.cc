#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	char s[100010], t;
	while(~scanf("%s", s))
	{
		int p = 0, l = strlen(s);
		while((t = getchar())!='\n')
		{
			if(t == s[p])
				p++;
		}
		if(p == l)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}