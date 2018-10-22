#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int num[15];
int gcd(int x, int y)
{
	if(!x)
		return y;
	if(!y)
		return x;
	return gcd(y, x%y);
}
int main()
{
	char a[1000], b[1000];
	while(scanf("%s", a))
	{
		if(strcmp(a, "-1") == 0)
			break;
		scanf("%s", b);
		int lena = strlen(a), lenb = strlen(b);
		int _max = 0;
		for(int k = 0;k < lena;k++)
		{
			int s = 0;
			for(int i = k, j = 0;i < lena && j < lenb;i++, j++)
				if(a[i] == b[j])
					s++;
			if(s > _max)
				_max = s;
		}
		for(int k = 0;k < lenb;k++)
		{
			int s = 0;
			for(int j = k, i = 0;j < lenb && i < lena;i++, j++)
				if(a[i] == b[j])
					s++;
			if(s > _max)
				_max = s;
		}
		lena += lenb, _max *= 2;
		int g = gcd(lena, _max);
		if(!_max)
			printf("appx(%s,%s) = 0\n", a, b);
		else if(_max == lena)
			printf("appx(%s,%s) = 1\n", a, b);
		else
			printf("appx(%s,%s) = %d/%d\n", a, b, _max/g, lena/g);
	}
}