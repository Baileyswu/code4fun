#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n, s, i;
	while(~scanf("%d%d", &n,&s))
	{
		int c, y, mimi = 1000000;
		long long ans =0;
		while(n--)
		{
			mimi += s;
			scanf("%d%d", &c, &y);
			if(mimi > c)
				mimi = c;
			ans += mimi*y;
		}
		cout << ans << endl;
	}
	return 0;
}