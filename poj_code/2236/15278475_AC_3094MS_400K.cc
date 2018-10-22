#include <stdio.h>
#include <math.h>
#define N 1010
#define eps 1e-8
int n, m, L[N], f[N];
struct node{
	int x, y;
	node(){}
	node(int x, int y):x(x), y(y){}
	void sc() { scanf("%d%d", &x, &y); }
	double dis(node b){
		return sqrt(pow(x-b.x,2)+pow(y-b.y,2));
	}
}p[N];
int get(int x){
	if(f[x] != x) f[x] = get(f[x]);
	return f[x];
}
void merge(int x, int y){
	f[get(x)] = get(y);
}
void ask(int x, int y){
	if(get(x) == get(y))
		printf("SUCCESS\n");
	else
		printf("FAIL\n");
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++){
		p[i].sc();
		f[i] = i;
	}
	char str[10];
	int cnt = 0;
	while(~scanf("%s", str)){
		if(str[0] == 'O'){
			int ne; scanf("%d", &ne); ne--;
			L[cnt++] = ne;
			for(int i = 0;i < cnt-1;i++)
				if(p[L[i]].dis(p[ne])-m < eps)
					merge(L[i], ne);
		}
		else{
			int x, y; scanf("%d%d", &x, &y);
			x--; y--;
			ask(x, y);
		}
	}
	return 0;
}