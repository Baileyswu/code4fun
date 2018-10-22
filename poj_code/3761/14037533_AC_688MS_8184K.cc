
#include <stdio.h>

#define MOD 20100713

__int64 power(__int64 a,__int64 p,__int64 m)
{
    __int64 ans = 1;
    while(p)
    {
        if(p&1)
            ans = ans * a % m;
        p >>= 1;
        a = a * a % m;
    }
    return ans;
}
__int64 fac[1000001] = {1};
int main()
{
    for(int i = 1; i < 1000001; ++i)
        fac[i] = fac[i-1] * i % MOD;
    int t;
    __int64 n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d",&n,&k);
        printf("%I64d\n",(power(k+1,n-k,MOD)-power(k,n-k,MOD) + MOD) % MOD * fac[k] % MOD);
    }
    return 0;
}
