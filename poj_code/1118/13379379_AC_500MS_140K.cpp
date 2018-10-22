#include <iostream>
#include <cstdio>
using namespace std;
struct point
{
    int x;
    int y;
}p[709];
int i,j,k;
int main ()
{
    int n,sum,ans;
    while(~scanf("%d",&n)&&n>0)
    {
        ans=-1;
        for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                sum=0;
                for(k=j+1;k<n;k++)
                {   
                    if((p[j].y-p[i].y)*(p[k].x-p[j].x)==(p[k].y-p[j].y)*(p[j].x-p[i].x))
                    sum++;
                }
                if(sum>ans)
                    ans=sum;
            }
        printf("%d\n",ans+2);
    }
return 0;

}