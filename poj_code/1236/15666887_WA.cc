#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
std::vector<int> v[110];
int in[110], out[110];
int main()
{
	int n;
	while(~scanf("%d", &n)){
		memset(v, 0, sizeof(v));
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for(int i = 0;i < n;i++){
			int u;
			while(scanf("%d", &u), u){
				in[u]++;
				out[i]++;
				u--;
				v[i].push_back(u);
			}
		}
		int a = 0, b = 0;
		for(int i = 0;i < n;i++){
			// printf("%d %d %d\n",  i+1, in[i], out[i]);
			if(in[i] == 0) a++;
			if(out[i] == 0) b++;
		}
		printf("%d\n%d\n", a, b);
	}
	return 0;
}