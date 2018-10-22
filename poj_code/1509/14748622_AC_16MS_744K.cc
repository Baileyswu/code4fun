#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int smallest(string s)
{
	int i, j, k, l;
	int N = s.length();
	s += s;
	for(i = 0, j = 1;j < N && i < N;)
	{
		if(i == j)
			j++;
		for(k = 0;k < N && s[i+k] == s[j+k];k++);
		if(k >= N)
			break;
		if(s[i+k] < s[j+k])
			j += k+1;
		else
			i += k+1;
	}
	return min(i, j);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		string s;
		while(cin >> s)
			printf("%d\n", smallest(s)+1);
	}
	return 0;
}