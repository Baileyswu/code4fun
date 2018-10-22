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
	int ans,lasth,totalw,n,i,curarea;
	while(scanf("%d",&n) && n != -1)
	{
		stack <rec>s;
		ans = 0, lasth = 0;
		for(i = 0;i < n;i++)
		{
			scanf("%d%d",&data.w,&data.h);
			if(lasth < data.h)
				s.push(data);
			else
			{
				totalw = 0;
				while(!s.empty() && s.top().h >= data.h)//easy to leave out !s.empty()
				{
					totalw += s.top().w;
					curarea = s.top().h * totalw;
					if(curarea > ans)
						ans = curarea;
					s.pop();
				}
                totalw += data.w;//easy to forget update the data.w
                data.w = totalw;
				s.push(data);
			}
			lasth = s.top().h;
		}
		totalw = 0;
		while(!s.empty())
		{
			totalw += s.top().w;
			curarea = s.top().h * totalw;
			if(curarea > ans)
				ans = curarea;
			s.pop();
		}
		printf("%d\n", ans);
	}
	return 0;
}
