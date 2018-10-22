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
LL mult_mod(LL a,LL b,LL c)
{
    a%=c;
    b%=c;
    LL ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}



//计算  x^n %c
/*LL po(LL x,LL n,LL mod)//x^n%c
{
    if(n==1)return x%mod;
    x%=mod;
    LL tmp=x;
    LL ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}*/
LL po(LL a, LL k, LL m)
{
	if(k == 0) return 1;
	if(k == 1) return a;
	LL t = po(a, k/2, m);
	t = mult_mod(t, t, m);
	if(k & 1LL)
		t = mult_mod(t, a, m);
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

bool recheck(LL a, LL n, LL m, LL j)
{
	a %= n;
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
		x0 = (mult_mod(x0,x0,x) + c)%x;//迭代公式为(x0^x0+c)%x
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