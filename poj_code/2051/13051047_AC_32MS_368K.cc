#include <stdio.h>
typedef struct node
{
	int ID;
	int period;
	long long time;
}Node;
Node heap[1005];
static int hlength;
int down(int p)
{
	int q = 2 * p;
	Node a = heap[p];
	while(q <= hlength)
	{
		if(q < hlength)
			if(heap[q].time > heap[q+1].time || (heap[q].time == heap[q+1].time && heap[q].ID > heap[q+1].ID))
				q++;
		if(a.time < heap[q].time || (a.time == heap[q].time && a.ID <= heap[q].ID))
			break;
		else
		{
			heap[p] = heap[q];
			p = q;
			q = 2 * p;
		}
	}
	heap[p] = a;
	return 0;
}
int build()
{
	for(int i = hlength/2;i > 0;i--)
		down(i);
	return 0;
}
int main()
{
	int i = 1, k;
	Node data;
	char command[10];
	while(scanf("%s", command) && command[0] != '#')
	{
		scanf("%d%d", &heap[i].ID, &heap[i].period);
		heap[i].time = heap[i].period;
		i++;
	}
	scanf("%d",&k);
	hlength = --i;
	build();
	while(k--)
	{
		printf("%d\n", heap[1].ID);
		heap[1].time += heap[1].period;
		down(1);
	}
	return 0;
}
