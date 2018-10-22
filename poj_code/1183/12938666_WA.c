#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
long int sum(long int a,long int b)
{
    R (b*b+1)/(b-a);
}
int main()
{
    long int a,b,s,min;
    S("%d",&a);
    b=a*a+a+1;
    min=sum(a,b);
    for(b=a+1;b<a*a+a+1;b++)
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
