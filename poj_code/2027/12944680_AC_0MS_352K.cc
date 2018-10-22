#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int n,x,y;
    S("%d",&n);
    while(n--)
    {
        S("%d%d",&x,&y);
        if(x<y)P("NO BRAINS\n");
        else P("MMM BRAINS\n");
    }
    R 0;
}
