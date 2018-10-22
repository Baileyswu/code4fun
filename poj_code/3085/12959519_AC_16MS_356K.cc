#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int t,n,i=1;
    S("%d",&t);
    while(t--)
    {
        S("%d",&n);
        P("%d %d QUARTER(S), ",i++,n/25);
        n=n%25;
        P("%d DIME(S), ",n/10);
        n=n%10;
        P("%d NICKEL(S), ",n/5);
        n=n%5;
        P("%d PENNY(S)\n",n);
    }
    R 0;
}
