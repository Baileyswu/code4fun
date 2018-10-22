#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int sum(int a,int b)
{
    R (b*b+1)/(b-a);
}
int main()
{
    int a,b,s,min=10000;
    S("%d",&a);
    for(b=a+1;b<a*a+2;b++)
    {
        if((b*b+1)%(b-a)==0)
        {
          s=sum(a,b);
          if(s<min)
            min=s;
        }
    }
    printf("%d\n",min);
    R 0;
}
