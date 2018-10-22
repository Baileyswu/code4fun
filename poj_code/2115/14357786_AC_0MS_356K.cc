#include <stdio.h>
#define LL long long
LL exGcd(LL a,LL b,LL &x,LL &y)//拓展欧几里德算法
{
   LL d,t;
   if(b==0) { x=1; y=0; return a; }
   d=exGcd(b,a%b,x,y);
   t=x; x=y; y=t-a/b*y;
   return d;
}
int main()
{
     LL a,b,c,x,y,d,r;
     int k;
     while(scanf("%lld%lld%lld%d",&a,&b,&c,&k))
     {
     	LL sum=1;
    	for(int i=0;i<k;i++)
        	sum*=2;
        if(a==0&&b==0&&c==0&&k==0)
             break;
        d = exGcd(c,sum,x,y);
        if((b-a)%d!=0) printf("FOREVER\n");
        else{
            x=x*(b-a)/d;
            r=sum/d;
            x=(x%r+r)%r;
            printf("%lld\n",x);
         }
     }
     return 0;
}