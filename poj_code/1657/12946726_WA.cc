#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int max(int x,int y)
{
    if(x>y)R x;
    else R y;
}
int abs(int x)
{
    if(x<0)x=0-x;
    R x;
}
int main()
{
    int t,x1,y1,x2,y2,step;
    char str[10];
    S("%d",&t);
    getchar();
    while(t--)
    {
        gets(str);
        x1=str[0]-'a'+1;
        y1=str[1]-'0';
        x2=str[3]-'a'+1;
        y2=str[4]-'0';
        if(x1==x2&&y1==y2)
        {
            P("0 0 0 0\n");
        }
        else{
        step=max(abs(x1-x2),abs(y1-y2));
        P("%d ",step);
        if((x1-x2)==(y1-y2)||x1==x2||y1==y2)
            step=1;
        else step=2;
        P("%d ",step);
        if(x1==x2||y1==y2)
            step=1;
        else step=2;
        P("%d ",step);
        if((x1-y1)%2!=(x2-y2)%2)
            P("Inf\n");
        else
        {
            if((x1-x2)==(y1-y2))
                step=1;
            else step=2;
            P("%d\n",step);
        }
        }
    }
    R 0;
}
