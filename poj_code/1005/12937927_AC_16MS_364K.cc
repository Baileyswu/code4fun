#include<stdio.h>
#include<math.h>
#define P printf
#define R return
#define S scanf
#define PI 3.14159265
int main()
{
    int t,i=0,year;
    float x,y,area;
    S("%d",&t);
    while(t--)
    {
        S("%f%f",&x,&y);
        area=PI*(x*x+y*y)/2;
        year=area/50+1;
        i++;
        P("Property %d: This property will begin eroding in year %d.\n",i,year);
    }
    P("END OF OUTPUT.\n");
    R 0;
}
