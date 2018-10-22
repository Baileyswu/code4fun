#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define N 751
#define M 1001
int n, m;
struct node
{
	int x, y;
	double dis[N];
}city[N];
int order[N];
vector<int>vet[N/2+1];
int ans;
int main()
{
	int i, j, k;
	double min;
	while(~scanf("%d", &n))
	{
		for(i = 1;i <= n;i++)
			scanf("%d%d", &city[i].x, &city[i].y);
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
				city[i].dis[j] = sqrt(pow(city[i].x-city[j].x,2)+pow(city[i].y-city[j].y,2));
		scanf("%d", &m);
		memset(order, 0, n);
		for(i = 1;i <= n;i++)
			vet[i].clear();
		int point = 1, temp, big, change, len;
		if(m)
		{
			scanf("%d%d", &i, &j);
			order[i] = 1;
			order[j] = 1;
			vet[1].push_back(i);
			vet[1].push_back(j);
			m--;
			while(m--)
			{
				scanf("%d%d", &i, &j);
				if(!order[i] && !order[j])
				{
					point++;
					order[i] = point, order[j] = point;
					vet[point].push_back(i);
					vet[point].push_back(j);
				}
				else if(order[i] && !order[j])
				{
					order[j] = order[i];
					vet[order[i]].push_back(j);
				}
				else if(!order[i] && order[j])
				{
					order[i] = order[j];
					vet[order[j]].push_back(i);
				}
				else
				{
					temp = order[i]<order[j]?order[i]:order[j];
					big = max(order[i], order[j]);
					len = vet[big].size();
					for(k = len - 1;k >= 0;k--)
					{
						change = vet[big][k];
						order[change] = temp;
						vet[big].pop_back();
						vet[temp].push_back(change);
					}
				}
			}
		}
		else
		{
			order[1] = 1;
			vet[1].push_back(1);
		}
		int count = vet[1].size();
		int head, tail, num;
		while(count < n)
		{
			double min = 1e5;
			for(i = 0;i < count;i++)
			{
				num = vet[1][i];
				for(j = 1;j <= n;j++)
				{
					if(order[j] != 1)
					{
						if(city[num].dis[j] < min)
						{
							min = city[num].dis[j];
							head = num, tail = j;
						}
					}
				}
			}
			if(!order[tail])
			{
				order[tail] = 1;
				vet[1].push_back(tail);
			}
			else
			{
				num = order[tail];
				len = vet[num].size();
				for(k = len - 1;k >= 0;k--)
				{
					change = vet[num][k];
					vet[1].push_back(change);
					order[change] = 1;
					vet[num].pop_back();
				}
			}
			printf("%d %d\n", head, tail);
			count = vet[1].size();
		}
	}
	return 0;
}