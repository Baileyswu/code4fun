#include <stdio.h>
#include <string.h>
int main()
{
	int row, col, start;
	while(scanf("%d%d%d", &row, &col, &start), row)
	{
		char mp[15][15];
		int ex[15][15][2], c = 1, x, y, v = 0, d[15][15], p, q;
		for(int i = 0;i < row;i++)
		{
			scanf("%s", mp[i]);
			for(int j = 0;j < col;j++)
			{
				switch(mp[i][j])
				{
					case 'N':x=-1, y=0;break;
					case 'E':x=0, y=1;break;
					case 'S':x=1, y=0;break;
					case 'W':x=0, y=-1;break;
				}
				ex[i][j][0] = x, ex[i][j][1] = y;
			}
		}
		x = 0, y = start-1;
		memset(d, 0, sizeof(d));
		while(x >= 0 && x < row && y >= 0 && y < col)
		{
			if(d[x][y])
			{
				v = 1;
				printf("%d step(s) before a loop of %d step(s)\n", d[x][y]-1, c - d[x][y]);
				break;
			}
			d[x][y] = c++;
			p = x, q = y;
			x += ex[p][q][0], y += ex[p][q][1];
		}
		if(!v)
			printf("%d step(s) to exit\n", c-1);
	}
	return 0;
}