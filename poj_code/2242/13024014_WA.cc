#include<stdio.h>
#define P 3.141592653589793
#include<math.h>
float pow2(float x)
{
    return x*x;
}
float l(float x1,float y1,float x2,float y2)
{
    return sqrt(pow2(x1-x2)+pow2(y1-y2));
}
int main()
{
    float x1,y1,x2,y2,x3,y3,a,b,c,A,r;
    while(~scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3))
    {
        a=l(x1,y1,x2,y2);
        b=l(x2,y2,x3,y3);
        c=l(x3,y3,x1,y1);
        A=acos((pow2(b)+pow2(c)-pow2(a))/(2*b*c));
        r=a/(2*sin(A));
        printf("%.2f\n",2*P*r);
    }
    return 0;
}
