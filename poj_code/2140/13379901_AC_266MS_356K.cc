#include <stdio.h>
int main()
{
    int n, i, count, x;
    while(~scanf("%d", &n))
    {
        count = 0;
        for(i = 1;i <= n;i++)
        {
            if(i % 2)
            {
                if(n % i == 0)
                    if(n / i - i / 2 > 0)
                        count++;
            }
            else
            {
                x = n / i;
                if(x * i + i / 2 == n && x - i / 2 > -1)
                    count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}