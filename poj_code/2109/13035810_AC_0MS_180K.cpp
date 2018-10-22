#include <stdio.h>
#include <math.h>
int main()
{
    double a,b;
    while(~scanf("%lf%lf",&a,&b))
        printf("%.0lf\n",pow(b,1.0/a));
    return 0;
}
