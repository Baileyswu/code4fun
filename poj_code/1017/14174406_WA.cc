#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[7];
int get(int x)
{
	int b[4] = {0,5,3,1};
	int c[4] = {0,7,6,5};
	switch(x)
	{
		case 0: return 0;
		default:if(a[2] < b[x])
				{
					a[1] = max(0, a[1]-((b[x]-a[2])*4+c[x]));
					a[2] = 0;
				}
				else
				{
					a[2] -= b[x];
					a[1] = max(0, a[1]-c[x]);
				}
				break;
	}
	return 1;
}
int fet(int x)
{
	if(!x)
		return 0;
	a[1] = max(0, a[1]-(9-x)*4);
	return 1;
}
int pr()
{
	for(int i = 1;i < 7;i++)
		printf("%d%c", a[i], " \n"[i==6]);
}
int main()
{
	while(1)
	{
		int key = 0;
		for(int i = 1;i < 7;i++)
		{
			scanf("%d", &a[i]);
			key |= a[i];
		}
		if(!key)
			break;
		int sum = a[6] + a[5] + a[4] + a[3]/4;
		a[1] = max(0, a[1]-a[5]*11);
		if(5*a[4] > a[2])
		{
			a[1] = max(0, a[1]-(5*a[4]-a[2])*4);
			a[2] = 0;
		}
		else
			a[2] -= 5*a[4];
		a[3] %= 4;
		sum += get(a[3]);
		sum += a[2]/9;
		a[2] %= 9;
		sum += fet(a[2]);
		sum += a[1]/36 + (1&(a[1]%36));
		//pr();
		printf("%d\n", sum);
	}
	return 0;
}