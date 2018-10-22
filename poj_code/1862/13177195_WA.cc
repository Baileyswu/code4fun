#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
static int hlength;
static double heap[101];
int down(int p)
{
	int q = 2 * p;
	double a = heap[p];
	while(q <= hlength)
	{
		if(q < hlength && heap[q] < heap[q+1])
			q++;
		if(a >= heap[q])
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
int up(int p)
{
	int q = p / 2;
	double a = heap[p];
	while(q > 0 && heap[q] < a)
	{
		heap[p] = heap[q];
		p = q;
		q = p / 2;
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
double DeleteMax()
{
	double r = heap[1];
	heap[1] = heap[hlength--];
	down(1);
	return r;
}
int insert(double a)
{
	heap[++hlength] = a;
	up(hlength);
	return 0;
}
int main()
{
	int i;
	double temp;
	scanf("%d", &hlength);
	for(i = 1;i <= hlength;i++)
		scanf("%lf", &heap[i]);
	if(hlength == 1)
		printf("%.3lf\n", heap[1]);
	else
	{
		build();
		while(hlength > 1)
		{
			temp = DeleteMax();
			temp = sqrt(DeleteMax() * temp) * 2;
			insert(temp);
		}
		printf("%.3lf\n", heap[1]);
	}
	return 0;
}