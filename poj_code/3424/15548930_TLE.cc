#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define N 110
#define M 1000000
set <string> ans;
set <string>::iterator iter;
int n;
struct node
{
	int x, y, z;
	node(){}
	node(int x, int y) : x(x), y(y) {}
	node operator + (const node &b){
		return node(x+b.x, y+b.y);
	}
	void pr(){
		printf("%d %d %d\n", x, y, z);
	}
}p[N], o, f;
char key[3][4] = {
	"123", "456", "789"
};
char t[N];
bool out(node &a){
	return a.x >= 300 || a.y >= 300 || a.x < 0 || a.y < 0;
}
bool solve(){
	if(out(f)) return false;
	for(int i = 0;i < 300-f.x;i++)
		for(int j = 0;j < 300-f.y;j++){
			string tp = "";
			for(int k = 0;k < n;k++){
				node q = p[k]+node(i,j);
				tp += key[q.y/100][q.x/100];
			}
			ans.insert(tp);
		}
	return true;
}
bool cmp(node a, node b){
	return a.x + b.x > a.y + b.y;
}
int main()
{
	while(~scanf("%d", &n)){
		ans.clear();
		o = node(M, M); f = node(-1, -1);
		for(int i = 0;i < n;i++){
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].z = i;
			p[i].y = 2000-p[i].y;
			o.x = min(o.x, p[i].x);
			o.y = min(o.y, p[i].y);
			f.x = max(f.x, p[i].x);
			f.y = max(f.y, p[i].y);
		}
		for(int i = 0;i < n;i++){
			p[i].x -= o.x;
			p[i].y -= o.y;
		}
		// for(int i = 0;i < n;i++)
			// p[i].pr();
		f.x -= o.x; f.y -= o.y;
		if(!solve()) printf("NONE\n");
		else {
			for(iter = ans.begin();iter != ans.end();iter++)
				printf("%s\n", iter->c_str());
		}
	}
	return 0;
}