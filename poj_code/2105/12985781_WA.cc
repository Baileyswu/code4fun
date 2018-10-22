#include<stdio.h>
#include<string.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
#define N 100
int main()
{
    int t,i,sum,q,k;
    char a[32];
    S("%d",&t);
    while(t--){
    S("%s",a);
    sum=0,q=128;
    for(i=0;i<8;i++)
    {
        a[i]-='0';
        sum+=a[i]*q;
        q/=2;
    }
    P("%d",sum);
    for(k=8;k<25;k=k+8)
    {sum=0,q=128;
    for(i=0;i<8;i++)
    {
        a[i+k]-='0';
        sum+=a[i+k]*q;
        q/=2;
    }
    P(".%d",sum);
    }
    P("\n");

    }
    R 0;
}
