/**************************************************

            模版：二维树状数组
            题目：CQBZ1909 二维区间的和

**************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn=1500+10;
 
int n,a[maxn][maxn];
 
void get_int(int &num)
{
    char c; bool f=false;
    for(; c=getchar(),c<'0'||c>'9'; (c=='-')&&(f=true));
    for(num=c-48; c=getchar(),c>='0'&&c<='9'; num=num*10+c-48);
    f&&(num=-num);
    return ;
}
 
void Add(int x, int y, int t)
{
    for(int i=x+1; i<=n; i+=lowbit(i))
        for(int j=y+1; j<=n; j+=lowbit(j))
            a[i][j]+=t;
    return ;
}
 
int Sum(int x,int y)
{
    int ans=0;
    for(int i=x+1; i; i-=lowbit(i))
        for(int j=y+1; j; j-=lowbit(j))
            ans+=a[i][j];
    return ans;
}
 
int main()
{
    int d, x1, y1, t, x2, y2;
 
    scanf("%d%d", &d, &n);
    while(scanf("%d",&d)&&d!=3)
    {
        if(d==1)
        {
            get_int(x1), get_int(y1), get_int(t);
            Add(x1,y1,t);
        }
        else
        {
            get_int(x1), get_int(y1), get_int(x2), get_int(y2);
            printf("%d\n", Sum(x2,y2)+ Sum(x1-1,y1-1)- Sum(x1-1,y2)- Sum(x2,y1-1));
        }
    }
    return 0;
}
