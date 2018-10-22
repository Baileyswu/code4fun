#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
struct rec
{
	int w;
	int h;
}data;
int main()
{
	long long n,ans,i,lasth,totalw,curarea;
	while(scanf("%lld",&n) && n != 0)
	{
		ans = 0;
		stack <rec>s;
		lasth = 0;
		for(i = 0;i < n;i++)
		{
			data.w = 1;
			scanf("%lld", &data.h);
			if(data.h >= lasth)
				s.push(data);
			else
			{
				totalw = 0;
				curarea = 0;
				while(!s.empty() && s.top().h > data.h)
				{
					totalw += s.top().w;
					curarea = totalw * s.top().h;
					if(curarea > ans)
						ans = curarea;
					s.pop();
				}
				totalw += data.w;
				data.w = totalw;
				s.push(data);
			}
			lasth = data.h;
		}
		totalw = 0;
		curarea = 0;
		while(!s.empty())
		{
			totalw += s.top().w;
			curarea = totalw * s.top().h;
			if(curarea > ans)
				ans = curarea;
			s.pop();
		}
		printf("%lld\n", ans);
	}
	return 0;
}