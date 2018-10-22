#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int n,i,s[15],t[15],newt[15],sum;
    while((S("%d",&n))!=EOF&&n!=-1)
    {
        for(i=0;i<n;i++)
            S("%d%d",&s[i],&t[i]);
        sum=s[0]*t[0];
        for(i=1;i<n;i++)
        {
            newt[i]=t[i]-t[i-1];
            sum+=s[i]*newt[i];
        }
        P("%d miles\n",sum);
    }
    R 0;
}
