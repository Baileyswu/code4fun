#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define N 1000110
string str, a;
int p[2*N];
int main()
{
	int o = 0;
	while(1){
		cin >> str;
		if(str == "END") break;
		int len = str.length();
		a = "#";
		for(int i = 0;i < len;i++){
			a += str[i];
			a += "#";
		}
		// cout <<"---" <<  a << endl;
		len = len*2+1;
		int id, m, ans;
		id = m = ans = 0;
		for(int i = 1;i < len;i++){
			if(i <= id) p[i] = 1;
			else p[i] = min(p[2*id-i], m-i);
			while(a[i+p[i]] == a[i-p[i]])
				p[i]++;
			ans = max(ans, p[i]);
			if(i > id){
				id = i;
				m = p[i] + i;
			}
		}
		printf("Case %d: %d\n", ++o, ans-1);
	}
	return 0;
}