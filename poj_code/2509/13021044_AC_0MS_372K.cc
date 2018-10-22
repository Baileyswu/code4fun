#include<stdio.h>
int cig(int n,int k)
{
    if(n>=0&&n<k)
        return n;
    else
    {
        return n/k*k+cig(n%k+n/k,k);
    }
}
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        printf("%d\n",cig(n,k));
    }
    return 0;
}
