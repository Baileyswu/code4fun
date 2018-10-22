#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[6][6]={
-1,5,1,-1,2,4,
2,-1,3,5,-1,0,
4,0,-1,1,3,-1,
-1,2,4,-1,5,1,
5,-1,0,2,-1,3,
1,3,-1,4,0,-1
};
int stand, face, x, y, z;
int turn(char c)
{
	int f, s;
	switch(c)
	{
		case 'l':face = dp[stand][face];break;
		case 'r':face = (dp[stand][face]+3)%6;break;
		case 'u':f = face;face = stand;stand = (f+3)%6;break;
		case 'd':s = stand;stand = face;face = (s+3)%6;break;
		case 'b':face = (face+3)%6;break;
	}
}
int go(int step)
{
	switch(face)
	{
		case 0: x += step;break;
		case 1: y += step;break;
		case 2: z += step;break;
		case 3: x -= step;break;
		case 4: y -= step;break;
		case 5: z -= step;break;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, step;
		x = y = z = 0, stand = 2, face = 0;
		char com[10];
		scanf("%d", &n);
		while(n--)
		{
			scanf("%s%d", com, &step);
			turn(com[0]);
			go(step);
		}
		printf("%d %d %d %d\n", x, y, z, face);
	}
	return 0;
}