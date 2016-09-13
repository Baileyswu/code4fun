/**************************************************

            模版：欧拉路径
            题目：HDU1116 play on words

**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=26+5;

int T, n, fa[maxn], in[maxn], out[maxn];

int Rt(int x)
{
    return (x==fa[x])?(x):(fa[x]=Rt(fa[x]));
}

void Init()
{
    memset(in, 0, sizeof in);
    memset(out, 0, sizeof out);
    for(int i=0; i<26; i++) fa[i]=i;
    return ;
}

bool Read()
{
    scanf("%d", &n);
    
    string s;
    int a, b;
    for(int i=1; i<=n; i++)
    {
        cin>>s;
        a=s[0]-'a', b=s[s.size()-1]-'a';
        ++in[a], ++out[b];
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
        else if(in[i]==out[i]+1) ++_in;
        else if(in[i]+1==out[i]) ++_out;
        else return false;
    }
    return (_in==_out)&&(_in<2);
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        Init();
        if(Read()&&Work())  printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
