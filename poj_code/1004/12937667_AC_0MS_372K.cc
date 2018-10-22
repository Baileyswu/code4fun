#include<stdio.h>
int main()
{
float a[12],x=0;
int i;
for(i=0;i<12;i++)
{scanf("%f",&a[i]);
x+=a[i];}
x/=12;
printf("$%.2f\n",x);
return 0;
}
