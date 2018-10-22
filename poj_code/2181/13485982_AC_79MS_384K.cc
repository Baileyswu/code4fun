#include <stdio.h>
#define N 150005
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		int ans = 0;
		int head, tail, tmp, m = 0;
		scanf("%d", &head);
		tail = head;
		n--;
		while(n--)
		{
			scanf("%d", &tmp);
			if(tmp < tail)
			{
				tail = tmp;
				m = 0;
			}
			else
			{
				if(head == tail && tail > m)
					m = tail;
				ans += head - tail;
				tail = head = tmp;
			}
		}
		if(head == tail && tail > m)
			m = tail;
		else
			m = head;
		ans += m;
		printf("%d\n", ans);
	}
	return 0;
}