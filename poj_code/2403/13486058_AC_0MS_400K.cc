#include <stdio.h>
#include <string.h>
int main()
{
	int n, m, i, sala[1005];
	char key[1005][50], word[50];
	while(~scanf("%d%d", &m, &n))
	{
		for(i = 0;i < m;i++)
			scanf("%s%d", key[i], &sala[i]);
		while(n)
		{
			int ans = 0;
			while(scanf("%s", word) && word[0] != '.')
			{
				for(i = 0;i < m;i++)
					if(!strcmp(word, key[i]))
						ans += sala[i];
			}
			printf("%d\n", ans);
			n--;
		}
	}
	return 0;
}