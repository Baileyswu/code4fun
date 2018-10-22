#include<stdio.h>
#define P printf
#define R return
#define S scanf
#define N 10000
int main()
{
    float x,s,sum;
    int i;
    while((S("%f",&s))!=EOF&&s!=0)
    {
        sum=0;
        for(i=1;i<=N;i++)
        {
            sum+=1/(float)(i+1);
            if(sum>=s)break;
        }
        P("%d\n",i);
    }
    R 0;
}
