#include <stdio.h>
#include <string.h>
bool board[101][101];
int set()
{
	for(int i = 1;i < 100;i++)
		for(int j = 0;j < 100;j++)
			board[i][j] = true;
	return 0;
}
int tran(char command[])
{
	if(strcmp(command, "BLACK") == 0)
		return 1;
	if(strcmp(command, "WHITE") == 0)
		return 2;
	if(strcmp(command, "TEST") == 0)
		return 3;
}
int main()
{
	set();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char command[6];
		int x, y ,len;
		scanf("%s%d%d%d", command, &x, &y, &len);
		switch(tran(command))
		{
			case 1:for(int i = x;i <= x + len - 1;i++)
						for(int j = y;j <= y + len - 1;j++)
							board[i][j] = false;
			break;
			case 2:for(int i = x;i <= x + len - 1;i++)
						for(int j = y;j <= y + len - 1;j++)
							board[i][j] = true;
			break;
			case 3:int count = 0;
				for(int i = x;i <= x + len - 1;i++)
						for(int j = y;j <= y + len - 1;j++)
							if(board[i][j] == false)
								count++;
				printf("%d\n", count);
			break;
		}
	}
	return 0;
}