/**************************************************

            模版：轮廓线DP
            题目：URAL 1519 Formula 1

**************************************************/


#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=12+5, _hash=30007, maxn=1000000+10;
typedef long long lint;

int n, m, x, y, code[N], ch[N];
char mmp[N][N];
struct hashmap
{
	int cur, fir[_hash], nxt[maxn];
	lint st[maxn], f[maxn];
	void clear()
	{
		cur=0;
		memset(fir, 0, sizeof fir);
		return ;
	}
	void push(lint s, lint ans)
	{
		int u=s%_hash;//取余构造哈希函数
		for(int i=fir[u]; i; i=nxt[i])	if(st[i]==s)
		{
			f[i]+=ans;
			return ;
		}
		nxt[++cur]=fir[u], fir[u]=cur, st[cur]=s, f[cur]=ans;
		return ;
	}
}p[2];//滚动

int Read(int cnt=0)
{
	for(int i=1; i<=n; i++)
	{
		scanf("%s", mmp[i]+1);
		for(int j=1; j<=m; j++)	if(mmp[i][j]=='.') x=i, y=j, ++cnt;//(x, y) 终点坐标
	}
	return cnt;
}

void Decode(lint st)//解密
{
	for(int i=m; i>=0; i--)
	{
		code[i]=st&7;//n=12 两两配对最多6条不相交线段
		st>>=3;
	}
	return ;
}

lint Encode()//加密
{
	int cnt=0;
	lint st=0;
	memset(ch, -1, sizeof ch);
	ch[0]=0;
	for(int i=0; i<=m; i++)
	{
		if(ch[code[i]]==-1)	ch[code[i]]=++cnt;
		code[i]=ch[code[i]];//最小表示法 回路不交叉
		st<<=3;
		st|=code[i];
	}
	return st;
}

void Shift()
{
	for(int i=m; i; i--) code[i]=code[i-1];
	code[0]=0;
	return ;
}

void DP_blank(int i, int j, int u)
{
	for(int k=1, t; k<=p[u].cur; k++)
	{
		Decode(p[u].st[k]);
		int left=code[j-1], up=code[j];
		if(left&&up)
		{
			if(left==up)
			{
				if(i==x&&j==y)//终点
				{
					code[j-1]=code[j]=0;
					if(j==m)	Shift();//转移到新一行
					p[u^1].push(Encode(), p[u].f[k]);
				}
			}
			else
			{
				code[j-1]=code[j]=0;
				for(int h=0; h<=m; h++) if(code[h]==up) code[h]=left;//左线段右插头和右线段左插头合并
				if(j==m)	Shift();
				p[u^1].push(Encode(), p[u].f[k]);
			}
		}
		else if((left&&(!up)) || ((!left)&&up))
		{
			t=(left ? left : up);
			if(mmp[i][j+1]=='.')//插头向右转移
			{
				code[j-1]=0, code[j]=t;
				p[u^1].push(Encode(), p[u].f[k]);
			}
			if(mmp[i+1][j]=='.')//插头向下转移
			{
				code[j-1]=t, code[j]=0;
				if(j==m)	Shift();
				p[u^1].push(Encode(), p[u].f[k]);
			}
		}
		else
		{
			if(mmp[i][j+1]=='.'&&mmp[i+1][j]=='.')//构建新的联通块
			{
				code[j-1]=code[j]=6;//旧联通块最多5种
				p[u^1].push(Encode(), p[u].f[k]);
			}
		}
	}
	return ;
}

void DP_block(int i, int j, int u)
{
	for(int k=1; k<=p[u].cur; k++)
	{
		Decode(p[u].st[k]);
		code[j-1]=code[j]=0;
		if(j==m)	Shift();
		p[u^1].push(Encode(), p[u].f[k]);
	}
	return ;
}

lint Work()
{
	int u=0;
	lint ans=0;
	p[u].clear();
	p[u].push(0, 1);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		{
			p[u^1].clear();
			if(mmp[i][j]=='.')	DP_blank(i, j, u);
			else DP_block(i, j, u);
			u^=1;
		}
	for(int i=1; i<=p[u].cur; i++)	ans+=p[u].f[i];
	return ans;
}

int main()
{
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		if(!Read())	cout<<0<<endl;
		else cout<<Work()<<endl;
	}
	return 0;
}
