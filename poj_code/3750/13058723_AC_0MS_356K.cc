#include <stdio.h>
typedef struct node
{
	char name[16];
	int next;
	int last;	
}Node;
Node player[61];
int main()
{
	int t, i, w, s;
	char o;
	scanf("%d", &t);
	for(i = 0;i < t;i++)
	{
		scanf("%s", player[i].name);
		player[i].next = i + 1;
		player[i].last = i - 1;
	}
	player[t-1].next = 0;
	player[0].last = t - 1;
	scanf("%d%c%d", &w, &o, &s);
	Node point, temp;
	point = player[w - 1];
	while(t--)
	{
		for(i = 0;i < s - 1;i++)
		{
			temp = player[point.next];
			point = temp;
		}
		printf("%s\n", point.name);
		player[point.next].last = point.last;
		player[point.last].next = point.next;
		point = player[player[point.last].next];
		Node test = point;  
		w = 10;
	}
	return 0;
}