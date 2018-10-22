#include <cstdio>
#include <cstring>
#include <queue>
#define N 10010
using namespace std;
typedef struct Node
{
	int pri, co;
}H;
queue <H>step;
int num[N], used[1070];
int set()
{
	memset(num, 1, sizeof(num));
	num[0] = num[1] = 0;
	for(int i = 2;i < N;i++)
		if(num[i])
			for(int j = 2*i;j < N;j+=i)
				num[j] = 0;
	return 0;
}
int main()
{
	set();
	int t, a, b, p, k, i, j, at, di, f;
	H ah, tep;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &a, &b);
		p = 0, ah.pri = a, ah.co = 0;
		used[p++] = a, num[a] = 0;
		step.push(ah);
		while(a != b)
		{
			for(di = 0;di < 4;di++)
			{
				k = a, at = 1;
				for(i = 0;i < di;i++)
					k /= 10, at *= 10;
				k %= 10;
				for(i = 0;i < 10;i++)
				{
					if(i == k)
						continue;
					f = a +(i-k)*at;
					if(f < 1000)
						continue;
					if(num[f])
					{
						tep.pri = f, tep.co = ah.co + 1;
						step.push(tep);
						used[p++] = f, num[f] = 0;
					}
				}
			}
			ah = step.front();
			step.pop();
			a = ah.pri;
		}
		printf("%d\n", ah.co);
		for(i = 0;i < p;i++)
			num[used[i]] = 1;
		while(!step.empty())
			step.pop();
	}
	return 0;
}