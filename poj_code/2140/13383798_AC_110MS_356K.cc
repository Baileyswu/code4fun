#include <stdio.h>
int main()
{
    int n, i;
    while(~scanf("%d", &n))
    {
        int count = 0;
        for(i = 1;i <= n;i+=2)
            if(n % i == 0)
                count++;
        printf("%d\n", count);
    }
    return 0;
}