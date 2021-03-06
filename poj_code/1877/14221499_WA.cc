#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cmp(int x, int y)
{
	return x < y;
}
int main()
{
	int n, m, h[10000], all_water, o = 0;
	while(scanf("%d%d", &n, &m))
	{
		if(!n && !m)
			break;
		int i;
		for(i = 0;i < n*m;i++)
			scanf("%d", &h[i]);
		scanf("%d", &all_water);
		sort(h, h+m*n, cmp);
		int sum1 = 0, temp, sum2 = 0;
		i = 1;
		for(i = 1;i < n*m;i++)
		{
			temp = (h[i]-h[i-1])*i*100;
			sum2 = sum1;
			sum1 += temp;
			if(sum1 >= all_water)
				break;
		}
		double ans = 0.01*(all_water-sum2)/i + h[i-1];
		double p = 1.0*i/(n*m)*100;
		if(!all_water)
			ans = 0.00, p = 0.00;
		printf("Region %d\nWater level is %.2f meters.\n%.2lf percent of the region is under water.\n", ++o, ans, p);
	}
}