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
