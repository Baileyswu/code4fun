#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define inf 1e9
int num[250], order[250], p;
stack<int> st, s1, s2;
queue<int> ans;
int clear()
{
	while(!ans.empty())
		ans.pop();
	while(!st.empty())
		st.pop();
	while(!s1.empty())
		s1.pop();
	while(!s2.empty())
		s2.pop();
}
int cmp(int x, int y)
{
	return x < y;
}
int input(int n)
{
	for(int i = 0;i < n;i++)
	{
		scanf("%d", &num[i]);
		st.push(num[i]);
	}
	sort(num, num+n, cmp);
}
int tt(int n)
{
	while(!st.empty() && p < n && num[p] == st.top())
	{
		st.pop();
		ans.push(1);
		ans.push(3);
		p++;
	}
	//printf("yes\n");
	while(!s1.empty() && p < n && num[p] == s1.top())
	{
		s1.pop();
		ans.push(3);
		p++;
	}
	while(!s2.empty() && p < n && num[p] == s2.top())
	{
		s2.pop();
		ans.push(4);
		p++;
	}
}
int gao(int n)
{
	p = 0;
	while(p < n && !st.empty() && num[p] != st.top())
	{
		int a, b, c;
		if(!st.empty()) c = st.top();
		else c = inf;
		if(!s1.empty()) a = s1.top();
		else a = inf;
		if(!s2.empty()) b = s2.top();
		else b = inf;
		//printf("%d %d %d\n", a, b, c);
		if(c > a && c > b)
			return 0;
		else if(c <= a && c > b)
		{
			ans.push(1);
			s1.push(c);
			st.pop();
		}
		else if(c > a && c <= b)
		{
			ans.push(2);
			s2.push(c);
			st.pop();
		}
		else if(c < a && c < b)
		{
			if(a <= b)
			{
				ans.push(1);
				s1.push(c);
				st.pop();
			}
			else
			{
				ans.push(2);
				s2.push(c);
				st.pop();
			}
		}
		tt(n);
	}
	while(p < n)
	{
		int q = p;
		tt(n);
		//printf("%d %d\n", q, p);
		if(q == p)
			return 0;
	}
	return 1;
}
int pr()
{
	while(!ans.empty())
	{
		int s = ans.front();
		switch(s)
		{
			case 1:printf("push 1\n");break;
			case 2:printf("push 2\n");break;
			case 3:printf("pop 1\n");break;
			case 4:printf("pop 2\n");break;
		}
		ans.pop();
	}
}
int main()
{
	int n, o = 0;
	while(scanf("%d", &n), n)
	{
		printf("#%d\n", ++o);
		clear();
		input(n);
		int v = gao(n);
		if(!v)
			printf("impossible\n");
		else
			pr();
	}
	return 0;
}