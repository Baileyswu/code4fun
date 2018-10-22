/*-------------------------------
 * File Name: POJ 1625
 * Author: Bailey Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015/07/24
--------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define WN 110
#define AL 55
#define M 55
struct Trie
{
    int next[WN][AL], fail[WN], end[WN];
    int root, L, n;
	char ch[55];
	int dp[M][WN][100];
	//int dp[M][WN];
    int newnode()
    {
        for(int i = 0;i < AL;i++)
            next[L][i] = -1;
        end[L++] = 0;
        return L-1;
    }
    void init()
    {
        L = 0;
        root = newnode();
    }
    int hash(char p)
    {
    	int a = 0, b = n-1;
    	while(a <= b)
    	{
    		int mid = a+b >> 1;
    		if(ch[a] == p)
    			return a;
    		if(ch[b] == p)
    			return b;
    		if(ch[mid] == p)
    			return mid;
    		if(ch[mid] > p) b = mid;
    		else a = mid;
    	}
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;

        //printf("%s\n", buf);
        for(int i = 0;i < len;i++)
        {
        	int s = hash(buf[i]);
        	//printf("%d\n", s);
            if(next[now][s] == -1)
                next[now][s] = newnode();
            now = next[now][s];
        }
        end[now] = 1;
    }
    void build()
    {
        queue <int> Q;
        fail[root] = root;
        for(int i = 0;i < AL;i++)
            if(next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while(!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for(int i = 0;i < AL;i++)
            {
                if(next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                	end[next[now][i]] = end[next[fail[now]][i]] > 0 ? 1:end[next[now][i]];
                    Q.push(next[now][i]);
                }
            }
        }
    }
    void pin(int *a)
    {
    	int i;
    	for(i = 99;i >= 0;i--)
    		if(a[i])
    			break;
    	if(i == -1)
    		printf("0");
    	else for(;i >= 0;i--)
    		printf("%d", a[i]);
    	printf("\n");
    }
    void ADD(int *a,int *b)
	{
		//pin(a);
		//pin(b);
	    int c = 0;
	    for(int i = 0;i < 100;i++)
	    {
	    	a[i] += b[i] + c;
	    	c = a[i]/10;
	    	a[i] %= 10;
	    }
	    //pin(a);
	    //printf("\n");
	}
    void solve(int step)
    {
    	memset(dp, 0, sizeof(dp));
    	dp[0][0][0] = 1;
    	//dp[0][0] = 1;
    	for(int i = 0;i < L;i++)
    	{
    		if(end[i]) continue;
    		for(int j = 0;j < n;j++)
    		{
    			int thi = next[i][j];
    			if(end[thi]) continue;
    			for(int k = 1;k <= step;k++)
    				ADD(dp[k][thi], dp[k-1][i]);
    				//dp[k][thi] += dp[k-1][i];
    		}
    	}	
    	for(int i = 0;i < L;i++)
    	{
    		if(end[i]) continue;
    		ADD(dp[step][0], dp[step][i]);
    		//dp[step][0] += dp[step][i];
    	}
    	pin(dp[step][0]);
    	//printf("%d\n", dp[step][0]);
    }
    void pr()
    {
    	for(int i = 0;i < L;i++)
    	{
    		printf("%d %d %d\n", i, fail[i], end[i]);
    		for(int j = 0;j < n;j++)
	    		printf("       %d %d\n", j, next[i][j]);
	    }
    }
}ac;
char str[12][12];
int cmp(char a, char b)
{
	return a < b;
}
int main()
{
	int m, w;
	while(~scanf("%d%d%d", &ac.n, &m, &w))
	{
		getchar();
		gets(ac.ch);
		sort(ac.ch, ac.ch+ac.n, cmp);
		//printf("%s\n", ac.ch);
		ac.init();
		for(int i = 1;i <= w;i++)
		{
			scanf("%s", str[i]);
			ac.insert(str[i]);
		}
		ac.build();
		//ac.pr();
		ac.solve(m);
	}
	return 0;
}