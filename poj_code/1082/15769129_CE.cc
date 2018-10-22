#include <bits/stdc++.h>
using namespace std;
int mon[12] = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31
};
int sg[105][12][31], h[5];
int main(){
	memset(sg, 0, sizeof(sg));
	for(int i = 2001;i >= 1900;i--){
		int yeap = (i%400==0 || ((i%100) && (i%4 == 0))) ? 1 : 0;
		for(int j = 12;j > 0;j--)
			for(int k = 31;k > 0;k--){
				if(i*10000+j*100+k >= 20011104){
					sg[i-1900][j-1][k-1] = 0;
					continue;
				}
			//	if(i == 2000)
			//	printf("%d:%d:%d %d   ", i, j, k, yeap);
				memset(h, 0, sizeof(h));
				int mth = mon[j-1];
				if(j == 2) mth += yeap;
				int m = j-1+k/mth;
				int d = k%mth;
				int y = i-1900+m/12;
			//	printf("%d %d %d  sg = %d  %d\n", y+2001, m+1, d+1, sg[y][m][d], mth);
				h[sg[y][m][d]] = 1;

				mth = mon[j%12];
				if(j == 1) mth += yeap;
				if((k-1)%mth == k-1){
					y = i-1900+j/12;
					m = j%12;
					d = k-1;
					if((y+1900)*10000+(m+1)*100+d+1 <= 20011104){
					//	printf("%d %d %d  sg = %d  %d\n", y+2001, m+1, d+1, sg[y][m][d], mth);
						h[sg[y][m][d]] = 1;
					}
				}
				for(int s = 0;s < 5;s++)
					if(h[s] == 0){
						sg[i-1900][j-1][k-1] = s;
						break;
					}
			//	if(i==2000)
			//	printf("sg= %d\n", sg[i-1900][j-1][k-1]);
			}
	}
	int T;
	scanf("%d", &T);
	while(T--){
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		if(sg[y-1900][m-1][d-1])
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
