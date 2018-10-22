#include<stdio.h>
#define P 3.141592653589793
#include<math.h>
int main()
{
    float x1,y1,x2,y2,x3,y3,a,b,c,A,r;
    while(scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
        b=sqrt(pow(x2-x3,2.0)+pow(y2-y3,2.0));
        c=sqrt(pow(x3-x1,2.0)+pow(y3-y1,2.0));
        A=sqrt(1-pow((pow(b,2.0)+pow(c,2.0)-pow(a,2.0))/2.0/b/c,2.0));
        r=a/2.0/A;
        r=2.0*P*r;
        printf("%.2f\n",r);
    }
    return 0;
}
