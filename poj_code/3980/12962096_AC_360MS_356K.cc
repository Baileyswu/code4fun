#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int a,b;
    while((S("%d%d",&a,&b))!=EOF)
    {
        P("%d\n",a%b);
    }
    R 0;
}
