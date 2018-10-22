#include <stdio.h>
#include <string.h>
int main()
{
	char ori[10];
	int num[10], ans[10];
	int n, m;
	while(~scanf("%s%d%d", ori, &n, &m)){
		int len = strlen(ori), i, s = 0;
		for(i = 0;i < len;i++)
		{
			if(ori[i] >= 'A' && ori[i] <= 'Z')
				num[i] = ori[i]-'A'+10;
			else
				num[i] = ori[i]-'0';
			s *= n;
			s += num[i];
		}
		i = 0;
		while(s)
		{
			ans[i++] = s%m;
			s /= m;
		}
		len = i;
		if(len > 7)
		{
			printf("  ERROR\n");
			continue;
		}
		for(i = 0;i < len;i++)
		{
			if(ans[i] < 10)
				ori[6-i] = ans[i]+'0';
			else
				ori[6-i] = ans[i]-10+'A';
		}
		for(i = len;i < 7;i++)
			ori[6-i] = ' ';
		ori[7] = '\0';
		printf("%s\n", ori);
	}
	return 0;
}