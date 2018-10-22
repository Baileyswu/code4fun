#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int sim(int x,int y)
{
    int i,s,v=0;
    for(i=9;i>1;i--)
    {
        if(x%i==0&&y%i==0)
        {
            s=i;v=1;
            break;
        }
    }
    if(v==0)
        s=1;
    R s;
}
int main()
{
    char str[10];
    int a,b,c,d,e,f;
    while((S("%s",str))!=EOF)
    {
        a=str[0]-'0';
        b=str[2]-'0';
        c=str[4]-'0';
        d=str[6]-'0';
        if(b!=d)
        {
            e=b,f=d;
            b=b*d/sim(e,f);
            a=a*f/sim(e,f);
            c=c*e/sim(e,f);
        }
        if(str[3]=='+')
        {
            a=a+c;
        }
        else a=a-c;
        if(a==0)
            P("0\n");
        else
        {
            e=a,f=b;
            a=a/sim(e,f);
            b=b/sim(e,f);
            P("%d/%d\n",a,b);
        }
    }
    R 0;
}
