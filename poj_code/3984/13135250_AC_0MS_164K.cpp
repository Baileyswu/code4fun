#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
bool flag[5][5];
queue <int>x;
queue <int>y;
int pre[5][5];
int back(int z)
{
    int x = z / 5, y = z % 5;
    if(x == 0 && y == 0)
        return 0;
    int i = pre[x][y];
    back(i);
    printf("(%d, %d)\n", x, y);
    return 0;
}
int main()
{
    int a[5][5], i, j;
    for(i = 0;i < 5;i++)
        for(j = 0;j < 5;j++)
            scanf("%d", &a[i][j], flag[i][j] = false);
    x.push(0), y.push(0);
    while(x.front() < 4 || y.front() < 4)
    {
        int tepx = x.front(), tepy = y.front();
        flag[tepx][tepy] = true;
        if(tepx - 1 >= 0 && !a[tepx - 1][tepy] && !flag[tepx - 1][tepy])
            x.push(tepx - 1), y.push(tepy), pre[tepx - 1][tepy] = 5 * tepx + tepy;
        if(tepx + 1 < 5 && !a[tepx + 1][tepy] && !flag[tepx + 1][tepy])
            x.push(tepx + 1), y.push(tepy), pre[tepx + 1][tepy] = 5 * tepx + tepy;
        if(tepy - 1 >= 0 && !a[tepx][tepy - 1] && !flag[tepx][tepy - 1])
            x.push(tepx + 1), y.push(tepy + 1), pre[tepx][tepy - 1] = 5 * tepx + tepy;
        if(tepy + 1 < 5 && !a[tepx][tepy + 1] && !flag[tepx][tepy + 1])
            x.push(tepx), y.push(tepy + 1), pre[tepx][tepy + 1] = 5 * tepx + tepy;
        x.pop(), y.pop();
    }
    printf("(0, 0)\n");
    i = pre[4][4];
    back(i);
    printf("(4, 4)\n");
    return 0;
}