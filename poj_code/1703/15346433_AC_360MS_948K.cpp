#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 100100
int n, m, p[N], a[N];
int get(int x){
	if(x != p[x]){
		int t = get(p[x]);
		a[x] += a[p[x]]%2;
		p[x] = t;
	}
	return p[x];
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		char com[10];
		int u, v;
		for(int i = 0;i < n;i++){
			p[i] = i;
			a[i] = 0;
		}
		for(int i = 0;i < m;i++){
			scanf("%s%d%d", com, &u, &v);
			u--; v--;
			get(u); get(v);
			// for(int j = 0;j < n;j++)
				// printf("%d%c", p[j], " \n"[j==n-1]);
			if(com[0] == 'A'){
				if(p[u] != p[v]) printf("Not sure yet.\n");
				else if(a[u] % 2 == a[v] % 2) printf("In the same gang.\n");
				else printf("In different gangs.\n");
			}
			else{
				a[p[v]] %= 2;
				a[p[u]] = a[u]%2 == a[v]%2 ? 1:0;
				p[p[u]] = p[v];
			}
			/*for(int j = 0;j < n;j++)
				printf("%d%c", p[j], " \n"[j==n-1]);
			for(int j = 0;j < n;j++)
				printf("%d%c", a[j], " \n"[j==n-1]);
			printf("\n");*/
		}

	}
	return 0;
}