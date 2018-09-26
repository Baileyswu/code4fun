/**************************************************

  模版：高精度
  题目：高精度加减乘除

 **************************************************/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long lint;
const int MAXN=5000+10;

struct node
{
	lint s[MAXN], lim;
	node(){ memset(s, 0, sizeof s); s[0]=1LL; lim=10000LL; } //lim压4位 1-s[0]低到高位
	bool operator <(const node&t) const
	{
		if(s[0]!=t.s[0])    return s[0]<t.s[0];
		for(int i=s[0]; i>=1; i--)	if(s[i]!=t.s[i])    return s[i]<t.s[i];
		return false;
	}
	bool operator >(const node&t) const
	{
		if(s[0]!=t.s[0])    return s[0]>t.s[0];
		for(int i=s[0]; i>=1; i--)	if(s[i]!=t.s[i])    return s[i]>t.s[i];
		return false;
	}
	bool operator ==(const node&t) const
	{
		if(s[0]!=t.s[0])    return false;
		for(int i=1; i<=s[0]; i++)	if(s[i]!=t.s[i])    return false;
		return true;
	}
	void operator +=(lint t) // 高精度数加单数 末位相加再进位
	{
		s[1]+=t;
		for(int i=1; i<=s[0]; i++)
		{
			s[i+1]+=(s[i]/lim), s[i]%=lim;
			if(i==s[0]&&s[i+1])	++s[0];
		}
		return ;
	}
	node operator +(lint t)
	{
		node tp=*this;	tp+=t;
		return tp;
	}
	void operator +=(node t) // 高精度数加高精度数 逐位相加再进位
	{
		s[0]=max(s[0], t.s[0]);
		for(int i=1; i<=s[0]; i++)    s[i]+=t.s[i];
		for(int i=1; i<=s[0]; i++)
		{
			s[i+1]+=(s[i]/lim), s[i]%=lim;
			if(i==s[0]&&s[i+1]) ++s[0];
		}
		return ;
	}
	node operator +(node t)
	{
		node tp=*this;	tp+=t;
		return tp;
	}
	void operator -=(lint t) // 高精度数减单数 末位相减再借位 判断是否降位
	{
		s[1]-=t;
		for(int i=1; s[i]<0&&i<s[0]; i++)	if(s[i]<0)   s[i]+=lim, s[i+1]-=1;
		for(; !s[s[0]]&&s[0]>1; --s[0]); // 高位为0 降位
		return ;
	}
	node operator -(lint t)
	{
		node tp=*this;	tp-=t;
		return tp;
	}
	void operator -=(node t) // 高精度数减高精度数 逐位相减 同时借位
	{
		for(int i=1; i<=s[0]; i++)
		{
			if(s[i]<t.s[i]) s[i]+=lim, s[i+1]-=1;
			s[i]-=t.s[i];
		}
		for(; !s[s[0]]&&s[0]>1; --s[0]);
		return ;
	}
	node operator -(node t)
	{
		node tp=*this;	tp-=t;
		return tp;
	}
	void operator *=(lint t) // 高精度数乘单数 逐位相乘再进位
	{
		for(int i=1; i<=s[0]; i++)    s[i]*=t;
		for(int i=1; i<=s[0]; i++)
		{
			s[i+1]+=(s[i]/lim), s[i]%=lim;
			if(i==s[0]&&s[i+1]) ++s[0];
		}
		return ;
	}
	node operator *(lint t)
	{
		node tp=*this;	tp*=t;
		return tp;
	}
	void operator *=(node t) // 高精度数乘高精度数 逐位相乘再进位
	{
		node tp;
		tp.s[0]=s[0]+t.s[0]-1;
		for(int i=1; i<=s[0]; i++)
			for(int j=1; j<=t.s[0]; j++)
				tp.s[i+j-1]+=s[i]*t.s[j]; // a[i]与b[j]相乘得到c[i+j-1] 
		for(int i=1; i<=tp.s[0]; i++)
		{
			tp.s[i+1]+=(tp.s[i]/lim), tp.s[i]%=lim;
			if(i==tp.s[0]&&tp.s[i+1]) ++tp.s[0];
		}
		*this=tp;
		return ;
	}
	node operator *(node t)
	{
		node tp=*this;	tp*=t;
		return tp;
	}
	void operator /=(lint t) // 高精度数除以单数 逐位相除 同时借位 判断是否降位
	{
		for(int i=s[0]; i>1; i--)	s[i-1]+=(s[i]%t*lim),  s[i]/=t;
		for(s[1]/=t; s[0]>1&&!s[s[0]]; --s[0]);
		return ;
	}
	node operator /(lint t)
	{
		node tp=*this;	tp/=t;
		return tp;
	}
	void operator /=(node t) // 高精度数除以高精度数 二分答案
	{
		node L, M, R=*this;
		while(L<R)
		{
			M=(L+R+1)/2;
			if((t*M)>*this) R=M-1;
			else L=M;
		}
		*this=L;
		return ;
	}
	node operator /(node t)
	{
		node tp=*this;	tp/=t;
		return tp;
	}
	void read(string st="")
	{
		cin>>st;	s[0]=st.size();
		for(int i=0, j; j=(s[0]-i-1)/4+1, i<s[0]; i++)  s[j]=s[j]*10+st[i]-'0';
		(s[0]%4)?(s[0]=s[0]/4+1):(s[0]/=4);
		return ;
	}
	void put()
	{
		printf("%lld", s[s[0]]);
		for(int i=s[0]-1; i; i--)  printf("%04lld", s[i]);
		return ;
	}
}A, B, C, D;

node Gcd(node a,node b)
{
	if(a.s[0]==1&&a.s[1]==0)  return b;
	if(b.s[0]==1&&b.s[1]==0)  return a;
	if((a.s[1]&1)&&(b.s[1]&1))  return (a>b) ? Gcd(a-b,b) : Gcd(b-a,a);
	if(a.s[1]&1)  return Gcd(a,b/2);
	if(b.s[1]&1)  return Gcd(a/2,b);
	return Gcd(a/2,b/2)*2;
}
int main()
{
	/*//plus
	A.read();
	B.read();
	C=A+B;
	C.put();*/

	/*//minus
	A.read();
	B.read();
	if(A<B)	{ putchar('-'); C=B-A;}
	else C=A-B;
	C.put();*/

	/*//multiply
	A.read();
	B.read();
	C=A*B;
	C.put();*/

	/*//divide
	A.read();
	B.read();
	C=A/B;
	C.put();
	D=A-B*C;
	putchar(' '), D.put();*/
	return 0;
}
