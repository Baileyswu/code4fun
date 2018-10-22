#include <stdio.h>
struct node
{
	int x, y;
}p1, p2, temp;
int main()
{
	int t;
	while(scanf("%d", &t), t)
	{
		scanf("%d%d", &p1.x, &p2.x);
		p2.x = p1.x, p2.y = p1. y;
		t--;
		while(t--)
		{
			scanf("%d%d", &temp.x, &temp.y);
			if(temp.x > p1.x || (temp.x==p1.x&&temp.y>p1.y))
				p1.x = temp.x, p1.y = temp.y;
			if(temp.y > p2.y || (temp.y==p2.y&&temp.x>p2.x))
				p2.x = temp.x, p2.y = temp.y;
		}
		if(p1.x == p2.x && p1.y == p2.y)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}