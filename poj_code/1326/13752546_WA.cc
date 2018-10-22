#include <stdio.h>
#include <string.h>
int main()
{
	char from[20], to[20], cla[5];
	int dis;
	long long ans = 0;
	while(scanf("%s", from))
	{
		if(!strcmp(from, "0"))
		{
			printf("%lld\n", ans);
			ans = 0;
			continue;
		}
		else if(!strcmp(from, "#"))
			break;
		scanf("%s%d%s", to, &dis, cla);
		if(cla[0] == 'F')
		{
			dis *= 2;
			printf("%d\n", dis);
			ans += (long long)dis;
		}
		else if(cla[0] == 'B')
		{	
			int v = dis%2;
			dis *= 1.5;
			dis += v;
			printf("%d\n", dis);
			ans += (long long)dis;
		}
		else if(cla[0] == 'Y')
		{
			if(dis < 500)
				dis = 500;
			printf("%d\n", dis);
			ans += (long long)dis;
		}
	}
	return 0;
}