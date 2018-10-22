/*--------------------------------------------
 * File Name: POJ 1107
 * Author: Danliwoo
 * Mail: Danliwoo@outlook.com
 * Created Time: 2015-10-06 19:25:58
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
struct node
{
	int pos;
	char c;
	node(){}
	node(int x, char y){
		pos = x, c = y;
	}
}p[3][200];
char str[200], ans[200];
int main()
{
	int k[3], b[3];
	while(scanf("%d%d%d", &k[0], &k[1], &k[2]))
	{
		if(!k[1] && !k[2] && !k[0]) break;
		scanf("%s", str);
		int len = strlen(str);
		ans[len] = '\0';
		b[0] = b[1] = b[2] = 0;
		for(int i = 0;i < len;i++)
		{
			if(str[i] >= 'a' && str[i] <= 'i')
				p[0][b[0]++] = node(i, str[i]);
			else if(str[i] >= 'j' && str[i] <= 'r')
				p[1][b[1]++] = node(i, str[i]);
			else if(str[i] == '_' || (str[i] >= 's' && str[i] <= 'z'))
				p[2][b[2]++] = node(i, str[i]);
		}
		for(int i = 0;i < 3;i++)
			for(int j = 0;j < b[i];j++)
				ans[p[i][(j+k[i])%b[i]].pos] = p[i][j].c;
		printf("%s\n", ans);
	}
	return 0;
}