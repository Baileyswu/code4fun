#include<stdio.h>
#include<math.h>
double fact(double n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
    double i,x;
    printf("0 1\n1 2\n2 2.5\n");
    x=2.5;
    for(i=3;i<10;i++)
        printf("%.0f %.9f\n",i,x=x+1/fact(i));
    return 0;
}
