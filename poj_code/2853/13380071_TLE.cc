#include <stdio.h>
int main()
{
    int n, hi, head, tail, count, i, t, p;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &p,&n);
        printf("%d ", p);
        hi = 0, head = 1, tail = 0, count = 0;
        for(i = 1;i <= n;i++)
        {
            hi += i;
            tail++;
            while(hi >= n)
            {
                if(hi == n)
                    count++;
                hi -= head++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}