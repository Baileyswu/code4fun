#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 1000005

int f[maxn];
char st[maxn];

int main()
{
    //freopen("t.txt", "r", stdin);
    int t = 1;
    while (1)
    {
        scanf("%s", st);
        int len = strlen(st);
        if (len == 1 && st[0] == '0')
            break;
        printf("%d. ", t++);
        for (int i = 0; i < len; i++)
            f[i] = st[len - i - 1] - '0';
        for (int i = 1; i < len; i++)
        {
            f[i] -= f[i - 1];
            if (f[i] < 0)
            {
                f[i] += 10;
                f[i + 1]--;
            }
        }
        if (f[len - 1] == 0)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for (int i = len - 1; i >= 0; i--)
            putchar(f[i] + '0');
        putchar('\n');
    }
    return 0;
}
