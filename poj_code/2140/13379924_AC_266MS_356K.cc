#include <stdio.h>
int main()
{
    int n, i, count, x;
    while(~scanf("%d", &n))
    {
        count = 0;
        for(i = 1;i <= n;i++)
        {
            if(i % 2 && n % i == 0 && n / i - i / 2 > 0)
                count++;
            else if(i % 2 == 0 && n / i - i / 2 > -1 && n / i * i + i / 2 == n)
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}