#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int num;
    int rank;
}p[10001];
int clear()
{
    int i;
    for(i=0;i<10001;i++)
    {
        p[i].rank=0;
        p[i].num=i;
    }
}
int cmp(struct node a, struct node b)
{
	if(a.rank == b.rank)
		return a.num < b.num;
	return a.rank > b.rank;
}
int main()
{
    int n,m,i,k,s,v;
    while(scanf("%d%d",&n,&m))
    {
    	v = 0;
        if(!n&&!m)break;
        clear();
        while(n--)
        {
            for(i=0;i<m;i++)
            {
                scanf("%d",&k);
                p[k].rank++;
            }
        }
        sort(p,p+10001,cmp);
        s = p[1].rank;
       	for(i = 1;i < 10001;i++)
       	{
       		if(p[i].rank < s)
       			break;
       		if(v)
       			printf(" ");
       		v = 1;
       		if(p[i].rank == s)
       			printf("%d", p[i].num);
       	}
       	printf("\n");
    }
}
