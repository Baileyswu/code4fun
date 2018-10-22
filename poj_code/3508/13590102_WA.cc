#include <stdio.h>
#include <string.h>
char str[1000001];
char ans[1000001];
int main()
{
	int i,l,p=0;
	while(scanf("%s",str))
	{
		if(str[0]=='0')
			break;
		l = strlen(str);
		ans[l-1]=str[l-1];
		for(i = l-2;i >= 0;i--)
		{
			if(str[i]<ans[i+1])
			{
				str[i]+=10;
				if(i)
					str[i-1]--;
			}
			ans[i] = str[i] - ans[i+1] + '0';
		}
		if(ans[0]=='0')
			printf("%d. IMPOSSIBLE\n",++p);
		else
			printf("%d. %s\n",++p, ans);
	}
	return 0;
}