#include <stdio.h>
#include <string.h>
int main()
{
	char irr[21][2][24], word[24];
	int L, N, i, len, v;
	scanf("%d%d", &L, &N);
	for(i = 0;i < L;i++)
		scanf("%s%s", irr[i][0], irr[i][1]);
	while(N--)
	{
		v = 0;
		scanf("%s", word);
		for(i = 0;i < L;i++)
			if(strcmp(word, irr[i][0]) == 0)
			{
				printf("%s\n", irr[i][1], v = 1);
				break;
			}
		if(v)
			continue;
		len = strlen(word);
		if(word[len - 1] == 'y')
		{
			if(word[len - 2] == 'a' || word[len - 2] == 'e' || word[len - 2] == 'i' || word[len - 2] == 'o' || word[len - 2] == 'u')
				word[len] = 's', word[len + 1] = '\0';
			else
			{
				word[len - 1] = 'i';
				word[len] = 'e';
				word[len + 1] = 's';
				word[len + 2] = '\0';
			}
		}
		else if(word[len - 1] == 'o' || word[len - 1] == 's' || word[len - 1] == 'x' ||(word[len - 1] == 'h' && (word[len - 2] == 'c' || word[len - 2] == 's')))
		{
			word[len] = 'e';
			word[len + 1] = 's';
			word[len + 2] = '\0';
		}
		else
		{
			word[len] = 's';
			word[len + 1] = '\0';
		}
		printf("%s\n", word);
	}
	return 0;
}