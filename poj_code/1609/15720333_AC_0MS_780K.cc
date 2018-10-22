/* 我们看看给的l和r的数据范围比较小，1到100，
那么我们使用一个dp数据记录dp[i][j]表示（i,j）出现的次数，
然后我们按照题目要求的规则便是需要i>=i'&&j>=j'，
于是我们定义状态dp[i][j]表示i'<=i&&j'<=j的最大的累加和，
那么我们可以找到状态转移方程为：
dp[i][j]=max(dp[i-1][j],dp[i][j-1])，
最后输出一个p的对应的最大的累加和就是要求的那个高度了。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 10010
struct node{
    int l,r;
    node(){}
    node(int tl,int tr)
    {
        l=tl;
        r=tr;
    }
}p[N];
int dp[110][110];
int main()
{
    int n,ans;
    while(scanf("%d",&n)&&n)
    {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&p[i].l,&p[i].r);
            dp[p[i].l][p[i].r]++;
        }
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
       		ans=max(ans, dp[p[i].l][p[i].r]);
        printf("%d\n",ans);
    }
    printf("*\n");
    return 0;
}
