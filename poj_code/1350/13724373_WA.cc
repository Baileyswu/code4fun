#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int num[4], ans;
int cmp(int a, int b)
{
	return a < b;
}
int solve(int x)
{
	sort(num, num+4, cmp);
	int mm, nn, ze;
	mm = num[0]*1000+num[1]*100+num[2]*10+num[3];
	switch(x)
	{
		case 4:nn = num[3]*1000+num[2]*100+num[1]*10+num[0];break;
		case 3:nn = num[3]*100+num[2]*10+num[1];break;
		case 2:nn = num[3]*10+num[2];break;
		case 1:nn = num[3];break;
	}
	int re = nn - mm;
	printf("%d-%d=%d\n", nn, mm, re);
	ans++;
	if(re == 0||re == 6174)
		return 0;
	num[0] = re%10;re/=10;
	num[1] = re%10;re/=10;
	num[2] = re%10;re/=10;
	num[3] = re%10;
	int i;
	for(i = 3;i > 0;i--)
		if(num[i])
			break;
	return solve(i+1);
}
int main()
{
	char str[5];
	while(~scanf("%s", str))
	{
		if(str[0] == '-')
			break;
		printf("N=%s:\n", str);
		int i;
		for(i = 0;i < 4;i++)
			num[i] = str[i] - '0';
		sort(num, num+4, cmp);
		if(num[0] == num[3])
		{
			printf("No!!\n");
			continue;
		}
		ans = 0;
		solve(4);
		printf("Ok!! %d times\n", ans);
		
	}
	return 0;
}
