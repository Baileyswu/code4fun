#include <stdio.h>
#include <string.h>
int dp(int x,int y);
int max( int x, int y);
int gaodu[100][100];
int f[100][100];
int hang,lie;
int main()
{
	scanf("%d%d",&hang,&lie);
	for(int i = 0;i < hang;i++){
		for(int j = 0;j < lie;j++)
		scanf("%d",&gaodu[i][j]);
	}
	memset(f, 0, sizeof(f));
	for(int i = 0;i < hang;i++){
		for(int j = 0;j < lie;j++)
			f[i][j] = dp(i,j);
	}
	int da = 0;
	for(int i = 0;i < hang;i++){
		for(int j = 0;j < lie;j++){
			if(f[i][j] > da){
				da = f[i][j];
			}
		}
	}
	for(int i = 0;i < hang;i++)
		for(int j = 0;j < lie;j++)
			printf("%d%c", f[i][j], " \n"[j==lie-1]);
	printf("%d",da);
	return 0;
}
int max(int x,int y){
	if(x >= y)
	return x;
	else return y;
}
int dp(int x,int y){
	if(f[x][y] != 0) return f[x][y];
	f[x][y] = 1;
	if(x >= 1&&gaodu[x-1][y] < gaodu[x][y]) f[x][y] = max(f[x][y],dp(x-1,y)+1);
	if(x < hang-1&&gaodu[x+1][y] < gaodu[x][y] ) f[x][y]= max(f[x][y],dp(x+1,y)+1);
	if(y < lie-1&&gaodu[x][y+1] < gaodu[x][y]) f[x][y] = max(f[x][y],dp(x,y+1)+1);
	if(y >= 1&&gaodu[x][y-1] < gaodu[x][y]) f[x][y] = max(f[x][y],dp(x,y-1)+1);
	return f[x][y];
}