
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define N 1002
#define M 102

int temp[M][N];
int yes[N], no[N];
char ch[M];

int main()
{
    int i, j;
    int n, m, times, count, key, max, cc, k;
    scanf("%d%d", &n, &times);

    for(i=0; i<times; i++)
    {
        scanf("%d", &m);
        m = m << 1;
        temp[i][0] = m;
        for(j=1; j<=m; j++)
        {
            scanf("%d", &temp[i][j]);
        }
        getchar();
        scanf("%c", &ch[i]);
    }

    for(i=0; i<times; i++)
    {
        m = temp[i][0];
        if(ch[i] == '=')
        {
            for(j=1; j<=temp[i][0]; j++)
                yes[temp[i][j]] = 1; //是好的

        }
        else if(ch[i] == '>')
        {
            for(j=1; j<=m/2; j++)
            {
                no[temp[i][j]]++;
            }
            for(; j<=m; j++)
            {
                no[temp[i][j]]--;
            }
        }
        else if(ch[i] == '<')
        {
            for(j=1; j<=m/2; j++)
            {
                no[temp[i][j]] --;
            }
            for(; j<=m; j++)
            {
                no[temp[i][j]] ++;
            }
        }
    }
    count = 0;

    max = 0;
    cc = 0;
/*统计yes为0的有几个，同时找出no绝对值找出最大的*/
    for(i=1; i<=n; i++)
    {
        if(!yes[i])
        {
            cc++;
            k = i;
            if(abs(no[i]) > max) 
            {
                max = abs(no[i]);
                key = i;
            }
        }
    }
    if(cc == 1)
        printf("%d\n", k);
    else
    {
        count = 0;
//统计no绝对值最大的有几个

        for(i=1; i<=n; i++)
        {
            if(abs(no[i]) == max)
            {
                count++;
                if(count > 1)
                {
                    break;
                }
            }
        }
        if(count == 1)
            printf("%d\n", key);
        else printf("0\n");
    }
    return 0;
}