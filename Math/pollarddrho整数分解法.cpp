/* 1. 生成两个整数a、b，计算p=(a-b,n)，直到p不为1或a,b出现循环为止。 
2. 若p=n，则n为质数；否则为n的一个约数。
分解n的具体步骤如下： 
1. 选取一个小的随机数x1 ，迭代生成xi=xi−1^2+k ，取k=1，若序列出现循环则退出。 
2. 计算p=gcd(xi−1−xi,n) 直到p>1,否则返回上一步。 
3. 若p=n,则n为素数。否则p为n的约数，继续分解p和n/p  */
//找出一个因子
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
        p = pollard_rho(p,c--);//c即k表示最大搜索次数？
    //值变化，防止死循环k
    findfac(p,k);
    findfac(n/p,k);
}

