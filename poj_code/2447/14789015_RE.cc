/*--------------------------------------------
 * File Name: POJ 2447
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 20:28:35
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
LL factor[10];
int tol;
LL gcd(LL x, LL y)
{
	x = x > 0 ? x : -x;
	return y == 0? x : gcd(y, x%y);
}
LL mult_mod(LL a, LL b, LL c)
{
    a %= c; b %= c;
    LL ret = 0, tmp = a;
    while(b)
    {
        if(b & 1LL)
        {
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret%c;
}

LL po(LL a, LL k, LL m)
{
	if(k == 0) return 1;
	if(k == 1) return a%m;
	LL t = po(a, k/2, m);
	t = mult_mod(t, t, m);
	if(k & 1LL) t = mult_mod(t, a, m);
	return t % m;
}
//从n-1的最大奇因子为指数开始判定
bool recheck(LL a, LL n, LL m, LL j)
{
    LL d = po(a, m, n);//对大数运算时里面的乘法要另外算mult_mod
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
    LL m = n-1, j = 0;
    while( !(m & 1LL) )
    {
        m >>= 1;
        j++;
    }
    for(int i = 0;i < 5;i++)
    {
        LL a  = rand()%(n-2) + 2;
        if( !recheck(a,n,m,j) )
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
        x0 = (mult_mod(x0,x0,x) + c)%x;//迭代公式为(x0*x0+c)%x
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
    if(n == 1)
        return;
    if(Miller_Rabin(n))
    {
        factor[tol++] = n;
        return;
    }
    LL p = n;
    int c = k;
    while( p >= n)
    {
    	//printf("p n --%d %d\n", p, n);
        p = pollard_rho(p,c--);//c即k表示最大搜索次数？
    }
    //值变化，防止死循环k
    //printf("pollar---%d\n", p);
    findfac(p,k);
    findfac(n/p,k);
}
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
    if(b==0){
    x = 1; y = 0;
    return a;
    }
    LL r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int main()
{
	LL C, E, N;
	while(~scanf("%lld%lld%lld", &C, &E, &N))
	{
		tol = 0;
		findfac(N, 107);
		//for(int i = 0;i < tol;i++)
			//printf("%d %lld\n", i, factor[i]);
		LL T = (factor[0]-1)*(factor[1]-1);
		LL x, y;
		extend_Euclid(E, T, x, y);
		x = (x%T+T)%T;
		LL ans = po(C, x, N);
		printf("%lld\n", ans);
	}
	return 0;
}