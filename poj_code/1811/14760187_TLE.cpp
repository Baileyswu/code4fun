/*--------------------------------------------
 * File Name: POJ 1811
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-25 22:32:04
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define LL long long
LL factor[200];
int tol;
LL po(LL a, LL k, LL m)
{
	a %= m;
	if(k == 0) return 1;
	LL t = po(a, k/2, m);
	t = t*t%m;
	if(k & 1LL)
		t *= a;
	return t % m;
}
LL bs(LL a)
{
	return a > 0? a : -a;
}
LL gcd(LL a, LL b)
{
	return b == 0 ? bs(a) : gcd(b, a%b);
}
bool recheck(LL a, LL n)
{
    LL m = n-1, j = 0;
    while( !(m & 1LL) )
    {
        m >>= 1;
        j++;
    }
    LL d = po(a, m, n);
    if(d == 1 || d == n-1)
        return true;
    for(int i = 0;i < j;i++)
    {
        d = d*d % n;
        if(d == 1 || d == n-1)
            return true;
    }
    return false;
}
bool Miller_Rabin(LL n)
{
    if( n < 2)return false;
    if( n == 2)return true;
    if( (n&1LL) == 0)return false;//偶数
    srand((unsigned) time (NULL));
    for(int i = 0;i < 5;i++)
    {
        LL a  = rand()%(n-2) + 2;
        if( !recheck(a,n) )
            return false;
    }
    return true;
}

LL pollard_rho(LL x,LL c)
{
	LL i = 1, k = 2;
	srand(time(NULL));
	LL x0 = rand()%(x-1) + 1;
	LL y = x0;
	while(1)
	{
		i++;
		x0 = (po(x0,x0,x) + c)%x;//迭代公式为(x0^x0+c)%x
		LL d = gcd(y - x0,x);//gcd返回一个绝对值
		if( d != 1 && d != x)
			return d;
		if(y == x0)
			return x;
		if(i == k)
		{
			y = x0;
			k += k;
		}
	}
}

//对n进行素因子分解，存入factor. k设置为107左右即可
void findfac(LL n,int k)
{
	while(tol && n && n % factor[tol-1] == 0)
		n /= factor[tol-1];
	if(n <= 1)
		return;
	//printf("n---%lld\n", n);
	if(Miller_Rabin(n))
	{
		factor[tol++] = n;
		return;
	}
	LL p = n;
	int c = k;
	while( p >= n)
	{
		p = pollard_rho(p,c--);//c即k表示最大搜索次数？
		//printf("p---%lld\n", p);
	}
	//值变化，防止死循环k
	findfac(p,k);
	findfac(n/p,k);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL n;
		scanf("%lld", &n);
		if(Miller_Rabin(n))
		{
			printf("Prime\n");
			continue;
		}
		tol = 0;
		findfac(n, 107);
		LL ans = factor[0];
		for(int i = 1;i < tol;i++)
			ans = min(ans, factor[i]);
		printf("%lld\n", ans);
		//for(int i = 0;i < tol;i++)
			//printf("%lld%c", factor[i], " \n"[i==tol-1]);
	}
	return 0;
}