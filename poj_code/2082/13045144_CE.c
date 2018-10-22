#include <stdio.h>
#include <malloc.h>

#define STACK_TYPE int

typedef struct STACK_NODE
{
	STACK_TYPE wide;
	STACK_TYPE height;
	struct STACK_NODE *next;
}StackNode;

static StackNode *head = (StackNode *)malloc(sizeof(StackNode));

int is_empty()
{
	return head->next == NULL;
}

int push(STACK_TYPE wide, STACK_TYPE height)
{
	StackNode *new_node;
	new_node = (StackNode *)malloc(sizeof(StackNode));
	new_node->wide = wide;
	new_node->height = height;
	new_node->next = head->next;
	head->next = new_node;
	return 0;
}

int pop()
{
	StackNode *temp;
	if(!is_empty())
	{
		temp = head->next;
		head->next = temp->next;
		free(temp);
	}
	return 0;
}

STACK_TYPE top_w()
{
	if(!is_empty())
		return head->next->wide;
	return 0;
}

STACK_TYPE top_h()
{
	if(!is_empty())
		return head->next->height;
	return 0;
}

int destroy_stack()
{
	StackNode *temp;
	while(!is_empty())
		pop();
	return 0;
}

int main()
{
	int n,w,h,i,max,x,v;
	while(scanf("%d",&n) && n != -1)
	{
	    push(0,0),max=0,v=0;
		for(i = 0;i < n;i++)
		{
			scanf("%d%d",&w,&h);
			while(top_h() >= h)
			{
			    int s = top_h() * top_w();
				if(s > max)
					max = s;
				x = top_w();
				pop();
				head->next->wide += x;
				v = 1;
			}
			if(top_h() == 0 && v)
				w += x;
			push(w,h);
		}
		while(top_h() != 0)
		{
			int s = top_h() * top_w();
			if(s > max)
				max = s;
			x = top_w();
			pop();
			head->next->wide += x;
		}
		printf("%d\n",max);

	}
	return 0;
}
