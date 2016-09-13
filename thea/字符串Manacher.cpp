/**************************************************

            模版：Manacher
            题目：POJ3974 Palindrome
            
**************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000000*2+10;
#define Max(a, b) ((a)>(b)?(a):(b))
#define Min(a, b) ((a)<(b)?(a):(b))

int main()
{
    int T=0;
    string t;
    while(cin>>t)
    {
        if(t[0]=='E')   break;

        string s="!*";
        for(int i=0, j=t.size(); i<j; i++)  s+=t[i], s+='*';
        
        int f[maxn]={0}, n=s.size();
        int id=0, mx=0, ans=0;
        for(int i=1; i<n; i++)
        {
            f[i]= (mx>i)? Min(f[id*2-i], mx-i): 1;
            while(s[i-f[i]]==s[i+f[i]])  ++f[i];
            ans=Max(ans, f[i]);
            if(i+f[i]>mx)   mx=i+f[i], id=i;
        }

        printf("Case %d: %d\n", ++T, ans-1);
    }
    return 0;
}
