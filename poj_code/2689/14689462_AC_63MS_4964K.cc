/*--------------------------------------------
 * File Name: POJ 2689
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-02 17:12:41
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define M 46350
#define NN 1000010
int num[M] = {0,0,1};
int prime[M] = {2}, pr = 1;
int na[NN], in[NN], p;
void set()
{
	for(int i = 2;i < M;i++)
		num[i] = 1;
	int m = sqrt((double)M);
	for(int i = 2;i <= m;i++)if(num[i])
		for(int j = i*i;j < M;j += i)
			num[j] = 0;
	for(int i = 3;i < M;i += 2)
		if(num[i])
			prime[pr++] = i;
	//printf("%d\n", prime[pr-1]);
};
void find(int n, int m, int &l, int &r)
{
	for(int i = 0;i <= m-n;i++)
		na[i] = 1;
	if(n == 1)
		na[0] = 0;
	for(int i = 0;i < pr && 2*prime[i] <= m;i++)
	{
		long long j = n/prime[i]*prime[i];
		j = j < n ? j + prime[i]:j;
		j = j == prime[i] ? j*2 :j;
		//printf("%d %d %lld\n", i, prime[i], j);
		for(;j <= m;j += prime[i])
		{
			//printf("j %lld\n", j);
			na[j-n] = 0;
		}
	}
	p = 0;
	//printf("-------------\n");
	for(int i = 0;i <= m-n;i++)
		if(na[i])
		{
			in[p++] = i+n;
			//printf("%d %d\n", p-1, in[p-1]);
		}
	if(p == 1 || p == 0)
		return;
	l = 0, r = 1;
	for(int i = 1;i < p-1;i++)
		if(in[i+1]-in[i] < in[l+1]-in[l])
			l = i;
	for(int i = 2;i < p;i++)
		if(in[i]-in[i-1] > in[r]-in[r-1])
			r = i;
}
int main()
{
	int n, m, l, r;
	set();
	while(~scanf("%d%d", &n, &m))
	{
		l = r = -1;
		find(n, m, l, r);
		if(l == -1)
			printf("There are no adjacent primes.\n");
		else
			printf("%d,%d are closest, %d,%d are most distant.\n", in[l], in[l+1], in[r-1], in[r]);
	}
	return 0;
}
