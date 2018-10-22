#include<stdio.h>
#define P 3.141592653589793
#include<math.h>
int main()
{
    double x1,y1,x2,y2,x3,y3,a,b,c,A,r;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        a=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        b=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
        c=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
        A=sqrt(1-pow((pow(b,2)+pow(c,2)-pow(a,2))/2/b/c,2));
        r=a/2/A;
        r=2*P*r;
        printf("%.2lf\n",r);
    }
    return 0;
}
