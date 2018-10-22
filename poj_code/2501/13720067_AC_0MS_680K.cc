#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
	int h = 0, m = 0, s = 0, hh, mm, ss, v = 0;
	double sum = 0, tim;
	char bl;
	while(~scanf("%d:%d:%d", &hh, &mm, &ss))
	{
		bl = getchar();
		tim = 1.0*((hh-h)*3600+(mm-m)*60+(ss-s))/3600;
		sum += v*tim;
		if(bl == ' ')
			scanf("%d", &v);
		else if(bl == '\n')	
			printf("%02d:%02d:%02d %.2f km\n", hh, mm, ss, sum);
		h = hh, m = mm, s = ss;
	}
	return 0;
}
