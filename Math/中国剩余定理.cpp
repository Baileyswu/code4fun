/*令Ni=M/mi,则(Ni,mi)=1,故存在xi,满足Nixi+miyi=1,
  即Nixi≡1(mod mi) 则sum(aiNixi) ≡ai(mod mi)
 */

//解方程组x=ai(mod mi) mi之间两两互质
int China(int r)
{
    int M = 1, ans = 0;
    for (int i = 0; i < r; ++i)
        M *= m[i];
    for(int i = 0;i < r;i++)
    {
        int N = M/m[i];
        int x, y;
        extend_Euclid(N, m[i], x, y);
        ans = (ans+a[i]*N*x)%M;
    }
    ans = (ans - a[r])%M;
    return (ans+M)%M;
}
