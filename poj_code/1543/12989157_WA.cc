#include<stdio.h>
#include<string.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
#define N 100
int main()
{
    int x,a,b,c,d;
    S("%d",&x);
    for(a=1;a<=x;a++)
        for(b=1;b<a;b++)
            for(c=b;c<a;c++)
                for(d=c;d<a;d++)
                {
                    if(a*a*a==b*b*b+c*c*c+d*d*d)
                        P("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);

                }

    R 0;
}
