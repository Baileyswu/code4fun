#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char dic[100000][20];
int order[100000];
typedef struct node
{
	char daring[20];
	int ans;
	int tran;
}Node;
Node ok[50000];
bool cmp(Node a, Node b)
{
	return a.tran < b.tran;
}
int main()
{
	int n, len, sum = 0, v;
	char number[20];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", number);
		len = strlen(number);
		for(int i = 0;i < len;i++)
		{
			if(number[i] == 'A'||number[i] == 'B'||number[i] == 'C')
				number[i] = '2';
			else if(number[i] == 'D'||number[i] == 'E'||number[i] == 'F')
				number[i] = '3';
			else if(number[i] == 'G'||number[i] == 'H'||number[i] == 'I')
				number[i] = '4';
			else if(number[i] == 'J'||number[i] == 'K'||number[i] == 'L')
				number[i] = '5';
			else if(number[i] == 'M'||number[i] == 'N'||number[i] == 'O')
				number[i] = '6';
			else if(number[i] == 'P'||number[i] == 'R'||number[i] == 'S')
				number[i] = '7';
			else if(number[i] == 'T'||number[i] == 'U'||number[i] == 'V')
				number[i] = '8';
			else if(number[i] == 'W'||number[i] == 'X'||number[i] == 'Y')
				number[i] = '9';
			else if(number[i] == '-'||number[i] == 'Q'||number[i] == 'Z')
			{
				for(int j = i;j < len - 1;j++)
					number[j] = number[j+1];
				number[len - 1] = '\0';
				len--;
				i--;
			}
		}
		if(sum == 0)
		{
			strcpy(dic[0], number);
			order[0] = 1;
			sum++;
			continue;
		}
		v = 0;
		for(int i = 0;i <= sum;i++)
		{
			if(strcmp(dic[i], number) == 0)
			{
				order[i]++;
				v = 1;
				break;
			}
		}
		if(v == 0)
		{
			strcpy(dic[sum++], number);
			order[--sum] = 1;
			sum++;
		}
	}
	printf("\n");
	int j = 0;
	for(int i = 0;i < sum;i++)
		if(order[i] > 1)
		{
			for(int k = 6;k > 2;k--)
				dic[i][k + 1] = dic[i][k];
			dic[i][3] = '-';
			strcpy(ok[j].daring, dic[i]);
			ok[j].ans = order[i];
			ok[j].tran = dic[i][0] * 1000000 + dic[i][1] * 100000 + dic[i][2] * 10000 + dic[i][3] * 1000 + dic[i][4] * 100 + dic[i][5] * 10 + dic[i][6];
			j++;
		}
	len = j;
	sort(ok, ok + len, cmp);
	for(j = 0;j < len;j++)
		printf("%s %d\n", ok[j].daring, ok[j].ans);
}