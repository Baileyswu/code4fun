#include<stdio.h>
#include<string.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
#define N 100
int main()
{
    int t;
    long int r,e,c;
    S("%d",&t);
    while(t--)
    {
        S("%d%d%d",&r,&e,&c);
        if(r+c<e)
            P("advertise\n");
        else if(r+c>e)
            P("do not advertise\n");
        else
            P("does not matter\n");
    }

    R 0;
}
