#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    long int a,b,c,s,min;
    S("%d",&a);
    b=a+1;
    c=a*a+a+1;
    min=b+c;
    for(b=a+2;b<a*a+a+1;b++)
    {
        if((a*b+1)%(b-a)==0)
        {
            c=(a*b+1)/(b-a);
            s=b+c;
            if(s<min)
                min=s;
        }
    }
    P("%d\n",min);
    R 0;
}
