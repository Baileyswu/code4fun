#include<stdio.h>
#define range 1000001
bool IsPrime[range+1];
int set(bool IsPrime[])
{
    int i,j;
    for(i=2;i<=range;i++)
        IsPrime[i]=true;
    IsPrime[0]=false;
    IsPrime[1]=false;
    for(i=2;i<=range;i++)
    {
        if(IsPrime[i])
        {
            for(j=2*i;j<=range;j+=i)
                IsPrime[j]=false;
        }
    }
    return 0;
}
int main()
{
    int i,a,d,count,n;
    set(IsPrime);
    while(scanf("%d%d%d",&a,&d,&n)&d!=0)
    {
        count=0;
        for(i=a;i<=range;i+=d)
        {
            if(IsPrime[i])
            {
                count++;
                if(n==count){printf("%d\n",i);break;}
		    }
	    }
    }
    return 0;
}
