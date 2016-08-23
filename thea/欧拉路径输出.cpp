/**************************************************

            模版：欧拉路径输出
            题目：POJ2337 catenyms

**************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000+10, maxm=26+5;
#define Min(a, b) ((a)<(b)?(a):(b))

int T, n, in[maxm], out[maxm], fa[maxm], root, put[maxn];
string s[maxn];
bool vis[maxn];

int Rt(int x)
{
    return (x==fa[x])?(x):(fa[x]=Rt(fa[x]));
}

void Init()
{
    root=maxm;
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    memset(vis, false, sizeof vis);
    for(int i=0; i<26; i++) fa[i]=i;
    return ;
}

bool Read()
{
    scanf("%d", &n);

    int a, b;
    for(int i=1; i<=n; i++)
    {
        cin>>s[i];
        a=s[i][0]-'a', b=s[i][s[i].size()-1]-'a';
        ++in[a], ++out[b];
        root=Min(root, a);
        fa[Rt(b)]=Rt(a);
    }

    a=Rt(a);
    for(int i=0; i<26; i++)
        if((in[i]||out[i])&&Rt(i)!=a)
            return false;
    return true;
}

bool Work()
{
    int _in=0, _out=0;
    for(int i=0; i<26; i++)
    {
        if(in[i]==out[i])   continue;
        else if(in[i]==out[i]+1) ++_in, root=i;
        else if(in[i]+1==out[i]) ++_out;
        else return false;
    }
    return (_in==_out)&&(_in<2);
}

bool Dfs(int x, int cnt)
{
    for(int i=1; i<=n; i++)
        if((!vis[i])&&s[i][0]-'a'==x)
        {
            vis[i]=true;
            put[cnt]=i;
            if(cnt==n||Dfs(s[i][s[i].size()-1]-'a', cnt+1)) return true;
            vis[i]=false;
        }
    return false;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        Init();
        if(Read()&&Work())
        {
            sort(s+1, s+1+n);
            Dfs(root, 1);
            for(int i=1; i<n; i++)  cout<<s[put[i]]<<'.';
            cout<<s[put[n]]<<endl;
        }
        else printf("***\n");
    }
    return 0;
}
