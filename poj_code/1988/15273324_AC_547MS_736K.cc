#include <cstdio>
using namespace std;
#define N 30010
int p[N], a[N], s[N];
int get(int x){
	if(p[x] != x){
		int t = get(p[x]);
		a[x] += a[p[x]];
		p[x] = t;
	}
	return p[x];
}
void merge(){
	int x, y;
	scanf("%d%d", &x, &y);
	int xp = get(x), yp = get(y);
	if(xp == yp) return;
	p[xp] = yp;
	a[xp] += s[yp];
	s[yp] += s[xp];
}
void ask(){
	int x;
	scanf("%d", &x);
	p[x] = get(x);
	printf("%d\n", a[x]);
}
int main(){
	int T;
	while(~scanf("%d", &T)){
		for(int i = 0;i < N;i++){
			p[i] = i;
			a[i] = 0;
			s[i] = 1;
		}
		while(T--){
			char str[10];
			scanf("%s", str);
			if(str[0] == 'M')
				merge();
			else
				ask();
		}
	}
	return 0;
}