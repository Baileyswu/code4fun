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
struct node
{
	int x, y;
	int dis[N];
}city[N];
struct nod
{
	int x, y;
	int dis;
}ans[N*N];
bool cmp(nod a, nod b)
{
	return a.dis < b.dis;
}
vector<int>vet[N];
int n, m, i, j, k, point, order[N];
int input()
{
	for(i = 1;i <= n;i++)
		scanf("%d%d", &city[i].x, &city[i].y);
	for(i = 1;i <= n;i++)
		for(j = 1;j <= n;j++)
			city[i].dis[j] = pow(city[i].x-city[j].x,2)+pow(city[i].y-city[j].y,2);
	scanf("%d", &m);
	for(i = 1;i <= n;i++)
		order[i] = 0;
	for(i = 1;i <= point;i++)
		while(!vet[i].empty())
			vet[i].pop_back();
}
int bute()
{
	int temp, big, change, len;
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
int merge()
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
		bute();
	}
}
int setsum()
{
	m = 0;
	for(i = 1;i <= n;i++)
		for(j = i;j <= n;j++)
			if(i != j && !(order[i] == 1 && order[j] == 1))
			{
				ans[m].x = i;
				ans[m].y = j;
				ans[m].dis = city[i].dis[j];
				m++;
			}
	sort(ans, ans + m, cmp);
}
int main()
{
	scanf("%d", &n);
	int v = 0;
	input();
	point = 1;
	if(!m)
	{
		order[1] = 1;
		vet[1].push_back(1);
	}	
	else
		merge();
	setsum();
	for(k = 0;k < m;k++)
	{
		i = ans[k].x, j = ans[k].y;
		if(order[i] == order[j])
			continue;
		bute();
		printf("%d %d\n", i, j, v = 1);
	}
	if(!v)
		printf("\n");
	return 0;
}