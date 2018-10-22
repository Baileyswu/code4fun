#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define N 1000110
char str[N], a[2*N];
int p[2*N];
int main()
{
    int o = 0;
    while(1){
        scanf("%s", str);
        if(str[0] == 'E') break;
        int len = strlen(str);
        a[0] = '#';
        for(int i = 0;i < len;i++){
            a[2*i+1] = str[i];
            a[2*i+2] = '#';
        }
        len = len*2+1;
        a[len] = '\0';
        // printf("%d %s\n", len, a);
        int id, m, ans;
        id = m = ans = 0;
        for(int i = 1;i < len;i++){
            if(i < id) p[i] = 1;
            else p[i] = min(p[2*id-i], m-i);
            while(i-p[i] >= 0 && i+p[i] < len && a[i+p[i]] == a[i-p[i]])
                p[i]++;
            ans = max(ans, p[i]);
            // printf("%d %d %d\n", i, ans, p[i]);
            if(i > id){
                id = i;
                m = p[i] + i;
            }
        }
        printf("Case %d: %d\n", ++o, ans-1);
    }
    return 0;
}