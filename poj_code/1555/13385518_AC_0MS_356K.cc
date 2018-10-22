#include <stdio.h>
#define P printf
int main()
{
    int a[9], start, i;
    while(~scanf("%d", &a[8]))
    {
        start = -1;
        if(a[8])
            start = 8;
        for(i = 7;i >= 0;i--)
        {
            scanf("%d", &a[i]);
            if(a[i] && start == -1)
                start = i;
        }
        if(start == -1)
        {
            P("0\n");
            continue;
        }
        if(!start)
        {
            P("%d\n", a[0]);
            continue;
        }
        if(start == 1)
        {
            if(a[1] == -1)
                P("-");
            else if(a[1] != 1)
                P("%d", a[1]);
            P("x");
            if(a[0] > 0)
                P(" + %d", a[0]);
            else if(a[0] < 0)
                P(" - %d", -a[0]);
            P("\n");
            continue;
        }
        if(a[start] == 1)
            P("x^%d", start);
        else if(a[start] == -1)
            P("-x^%d", start);
        else
            P("%dx^%d", a[start], start);
        for(i = start - 1;i > 1;i--)
        {
            if(!a[i])
                continue;
            if(a[i] == 1)
                P(" + ");
            else if(a[i] == -1)
                P(" - ");
            else if(a[i] > 0)
                P(" + %d", a[i]);
            else
                P(" - %d", -a[i]);
            P("x^%d", i);
        }
        if(a[1] == 1)
            P(" + ");
        else if(a[1] == -1)
            P(" - ");
        else if(a[1] > 0)
            P(" + %d", a[1]);
        else if(a[1] < 0)
            P(" - %d", -a[1]);
        if(a[1])
            P("x");
        if(a[0] > 0)
            P(" + %d", a[0]);
        else if(a[0] < 0)
            P(" - %d", -a[0]);
        P("\n");
    }
    return 0;
}