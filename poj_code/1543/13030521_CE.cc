#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int x,a,b,c,d,q,w,e,r;
    scanf("%d",&x);
    for(a=1;a<=x;a++)
        for(b=2;b<a;b++)
            for(c=b;c<a;c++)
                for(d=c;d<a;d++)
                {
                    q=a*a*a,w=b*b*b,e=c*c*c,r=d*d*d;
                    if(q==w+e+r)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                }

    R 0;
}