#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define max 20000
int minDiv[max], phi[max], sum[max];
void genPhi()
{
	for(int i = 1;i < max;i++)
		minDiv[i] = i;
	for(int i = 2;i*i < max;i++)
	{
		if(minDiv[i] == i)
		{
			for(int j = i*i;j < max;j += i)
				minDiv[j] = i;
		}
	}
	phi[1] = 1;
	for(int i = 2;i < max;i++)
	{
		phi[i] = phi[i/minDiv[i]];
		if((i/minDiv[i]) % minDiv[i] == 0)
			phi[i] *= minDiv[i];
		else
			phi[i] *= minDiv[i] - 1;
	}
}
int Prime[max], tot = 0;
bool valid[max*2];
int getPrime()
{
	memset(valid, true, sizeof(valid));
	for(int i = 2;i < max*2;i++)
	{
		if(valid[i])
			for(int j = i*i;j < max*2;j += i)
				valid[j] = false;
	}
	for(int i = 2;i < max;i++)
		if(valid[i])
			Prime[tot++] = i;
}
int get(int n)
{
	if(n < max)
		return phi[n];
	for(int i = 0;i < tot;i++)
	{
		if(n % Prime[i] == 0)
		{
			int temp = get(n/Prime[i]);
			if(n/Prime[i] % Prime[i] == 0)
				temp *= Prime[i];
			else
				temp *= Prime[i]-1;
			return temp;
		}
	}
	int m = sqrt(n)+1;
	for(int i = Prime[tot-1];i < m;i++)
	{
		if(n % i ==0)
		{
			int temp = get(n/i);
			return temp*(i-1);
		}
	}
}
int main()
{
	getPrime();
	genPhi();
	int n;
	while(scanf("%d", &n), n)
	{
		printf("%d\n", get(n));
	}
	return 0;
}