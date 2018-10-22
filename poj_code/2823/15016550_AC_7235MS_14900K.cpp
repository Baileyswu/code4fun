/*--------------------------------------------
 * File Name: poj 2823
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-12-19 17:16:35
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 1001000
int n, m;
struct node
{
	int x, y;//x = val   y = order
}a[N];
int L[N], R[N], al[N], ar[N];
inline bool scan_d(int &num)  //  这个就是 加速的 关键了     
{  
    char in;bool IsN=false;  
    in=getchar();  
    if(in==EOF)  
        return false;  
    while(in!='-'&&(in<'0'||in>'9')) in=getchar();  
    if(in=='-')   { IsN=true;num=0;}  
    else num=in-'0';  
    while(in=getchar(),in>='0'&&in<='9')  
    {  
        num*=10,num+=in-'0';  
    }  
    if(IsN)  
        num=-num;  
    return true;  
}  

int main()
{
	while(~scanf("%d%d", &n, &m))
	{
		for(int i = 0;i < n;i++)
		{
			scan_d(a[i].x);
			a[i].y = i;
		}
		int ls, lt, rs, rt;
		L[0] = R[0] = ls = lt = rs = rt = 0;
		for(int i = 1;i < m;i++)
		{
			while(ls <= lt && a[L[lt]].x <= a[i].x)
				lt--;
			L[++lt] = i;
			while(rs <= rt && a[R[rt]].x >= a[i].x)
				rt--;
			R[++rt] = i;
		}
		al[0] = L[0];  ar[0] = R[0];
		for(int i = m;i < n;i++)
		{
			if(a[L[ls]].y <= i-m)
				ls++;
			if(a[R[rs]].y <= i-m)
				rs++;
			while(ls <= lt && a[L[lt]].x <= a[i].x)
				lt--;
			L[++lt] = i;
			while(rs <= rt && a[R[rt]].x >= a[i].x)
				rt--;
			R[++rt] = i;
			al[i-m+1] = L[ls];  ar[i-m+1] = R[rs];
		}
		for(int i = 0;i <= n-m;i++)
			printf("%d%c", a[ar[i]].x, " \n"[i==n-m]);
		for(int i = 0;i <= n-m;i++)
			printf("%d%c", a[al[i]].x, " \n"[i==n-m]);

	}
	return 0;
}




