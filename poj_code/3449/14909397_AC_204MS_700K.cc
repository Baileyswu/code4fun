#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
struct point
{
	double x, y;
	point(){}
	point(double x, double y):x(x), y(y){}
	point operator - (const point &b) const {
		return point(x - b.x, y - b.y);
	}
	point operator + (const point &b) const {
		return point(x + b.x, y + b.y);
	}
	double operator * (const point &b) const {
		return x*b.y - y*b.x;
	}
	void pr(){
		printf("(%.2f, %.2f) ", x, y);
	}
};
int dis(double x)
{
	if(fabs(x) < 1e-8) return 0;
	return x > 0 ? 1 : -1;
}
bool kua(point A, point B, point P, point Q)
{
	int sa = dis((P-A)*(B-A));
	int sb = dis((Q-A)*(B-A));
	return sa * sb <= 0;
}
bool junc(point A, point B, point C, point D)
{
	// A.pr(), B.pr(), C.pr(), D.pr();
	// printf("\n");
	return dis(min(A.x, B.x) - max(C.x, D.x)) <= 0 &&
			dis(min(A.y, B.y) - max(C.y, D.y)) <= 0 &&
			dis(max(A.x, B.x) - min(C.x, D.x)) >= 0 &&
			dis(max(A.y, B.y) - min(C.y, D.y)) >= 0 &&
			kua(A, B, C, D) && kua(C, D, A, B);
}
struct single
{
	int n, m, crash[26], flag;
	point p[25];
	void initial(){
		flag = m = 0;
		memset(crash, 0, sizeof(crash));
	}
	void pr()
	{
		for(int i = 0;i < n;i++)
			printf("(%.2f %.2f)\n", p[i].x, p[i].y);
	}
	void square(){
		n = 4;
		scanf(" (%lf,%lf) (%lf,%lf)", &p[0].x, &p[0].y, &p[2].x, &p[2].y);
		point M = p[0]+p[2];
		M.x /= 2; M.y /= 2;
		p[1].x = M.x-p[0].y+M.y;
		p[1].y = M.y+p[0].x-M.x;
		p[3].x = M.x-p[2].y+M.y;
		p[3].y = M.y+p[2].x-M.x;
	}
	void rectangle(){
		n = 4;
		scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y);
		p[3] = p[0]-p[1]+p[2];
	}
	void line(){
		n = 2;
		scanf(" (%lf,%lf) (%lf,%lf)", &p[0].x, &p[0].y, &p[1].x, &p[1].y);
	}
	void triangle(){
		n = 3;
		scanf(" (%lf,%lf) (%lf,%lf) (%lf,%lf)", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y);
	}
	void polygon(){
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf(" (%lf,%lf)", &p[i].x, &p[i].y);
	}
}shape[26];
void init()
{
	for(int i = 0;i < 26;i++)
		shape[i].initial();
}
void input(char c)
{
	shape[c-'A'].flag = 1;
	char name[100];
	scanf("%s", name);
	//printf("%c %s\n", c, name);
	if(strcmp(name, "square") == 0)
		shape[c-'A'].square();
	else if(strcmp(name, "rectangle") == 0)
		shape[c-'A'].rectangle();
	else if(strcmp(name, "line") == 0)
		shape[c-'A'].line();
	else if(strcmp(name, "triangle") == 0)
		shape[c-'A'].triangle();
	else if(strcmp(name, "polygon") == 0)
		shape[c-'A'].polygon();
	//shape[c-'A'].pr();
}
void see(int i, int j)
{
	//printf("%c %c\n", i+'A', j+'A');
	int is = shape[i].n, js = shape[j].n;
	for(int k = 0;k < is;k++)
		for(int l = 0;l < js;l++)
			if(junc(shape[i].p[k], shape[i].p[(k+1)%is], shape[j].p[l], shape[j].p[(l+1)%js]))
			{
				//printf("-----------jun\n");
				shape[i].crash[j] = 1;
				shape[j].crash[i] = 1;
				shape[i].m++;
				shape[j].m++;
				return;
			}
}
void solve()
{
	for(int i = 0;i < 26;i++)
		for(int j = i+1;j < 26;j++)
			if(shape[i].flag && shape[j].flag)
				see(i, j);
	for(int i = 0;i < 26;i++) if(shape[i].flag)
	{
		if(shape[i].m == 0)
			printf("%c has no intersections\n", i+'A');
		else if(shape[i].m == 1)
		{
			printf("%c intersects with ", i+'A');
			for(int j = 0;j < 26;j++)
				if(shape[i].crash[j])
				{
					printf("%c\n", j+'A');
					break;
				}
		}
		else if(shape[i].m == 2)
		{
			printf("%c intersects with ", i+'A');
			for(int j = 0;j < 26;j++)
				if(shape[i].crash[j])
				{
					printf("%c and ", j+'A');
					break;
				}
			for(int j = 25;j >= 0;j--)
				if(shape[i].crash[j])
				{
					printf("%c\n", j+'A');
					break;
				}
		}
		else
		{
			printf("%c intersects with ", i+'A');
			int k = 0;
			for(int j = 0;j < 26;j++)
			{
				if(k == shape[i].m-1)
					break;
				if(shape[i].crash[j])
				{
					printf("%c, ", j+'A');
					k++;
				}
			}
			for(int j = 25;j >= 0;j--)
				if(shape[i].crash[j])
				{
					printf("and %c\n", j+'A');
					break;
				}
		}
	}
}
int main()
{
	char str[5];
	while(~scanf("%s", &str))
	{
		char c = str[0];
		if(c == '.') break;
		if(c == '-') {
			solve();
			printf("\n");
			init();
			continue;
		}
		input(c);
	}
	return 0;
};