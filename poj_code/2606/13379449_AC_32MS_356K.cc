#include <stdio.h>
struct node
{
    int x, y;
}p[201];
int main()
{
    int n, i, j, k, temx, temy, max, sum;
    while(~scanf("%d", &n) && n)
    {
        for(i = 0;i < n;i++)
            scanf("%d%d", &p[i].x, &p[i].y);
        max = 1;
        for(i = 0;i < n - 2;i++)
            for(j = i + 1;j < n - 1;j++)
            {
                temx = p[i].x - p[j].x;
                temy = p[i].y - p[j].y;
                sum = 2;
                for(k = j + 1;k < n;k++)
                {
                    if(temx * (p[i].y - p[k].y) == temy * (p[i].x - p[k].x))
                        sum++;
                }
                if(sum > max)
                    max = sum;
            }
        printf("%d\n", max);
    }
    return 0;
}