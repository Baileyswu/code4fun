#include <stdio.h>
int main()
{
    int n, hi, head, tail, count, i;
    while(~scanf("%d", &n))
    {
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