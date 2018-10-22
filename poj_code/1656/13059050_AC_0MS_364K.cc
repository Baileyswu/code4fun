#include <stdio.h>
#include <string.h>
bool board[101][101];
int tran(char command[])
{
	if(strcmp(command, "BLACK") == 0)
		return 1;
	if(strcmp(command, "WHITE") == 0)
		return 0;
	if(strcmp(command, "TEST") == 0)
		return -1;
}
int main()
{
	int t, x, y ,len, i, j;
	for(i = 1;i <= 100;i++)
		for(j = 1;j <= 100;j++)
			board[i][j] = 0;
	scanf("%d", &t);
	while(t--)
	{
		char command[6];
		scanf("%s%d%d%d", command, &x, &y, &len);
		if(tran(command) >= 0)
		{
			for(i = x;i <= x + len - 1;i++)
				for(j = y;j <= y + len - 1;j++)
					board[i][j] = tran(command);
		}
		else if(tran(command) == -1)
		{
			int count = 0;
			for(i = x;i <= x + len - 1;i++)
				for(j = y;j <= y + len - 1;j++)
					if(board[i][j] == 1)
						count++;
			printf("%d\n", count);
		}
	}
	return 0;
}