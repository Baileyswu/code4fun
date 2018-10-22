#include <stdio.h>
#define N 21252
int extend_Euclid(int a, int b, int &x, int &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int main()
{
    int p, e, i, d, x1, y1, y2, z2, k, l, o = 0;
    int d1 = extend_Euclid(23, -28, x1, y1);
    int d2 = extend_Euclid(28, -33, y2, z2);
    int d3 = extend_Euclid(33, -23, l, k);
    //printf("%d %d %d   %d %d %d\n", x1, y1, d1, y2, z2, d2);
    while(scanf("%d%d%d%d", &p, &e, &i, &d))
    {
    	if(p == -1)
    		break;
    	int x0 = x1 * (e-p) / d1;//28/d1*K
    	int y0 = y1 * (e-p) / d1;//23/d1*K
    	int y00 = y2 * (i-e) / d2;
    	int z00 = z2 * (i-e) / d2;
    	int k0 = k * (y0-y00) / d3;
    	/*int t = 33/d3; t = t < 0? -t:t;
    	k0 = (k0%t+t)%t;*/
    	int l0 = l * (y0-y00) / d3;
    	int y = y0 + 23*k0;
    	int day = e + 28*y;
    	int ans = (day%N + N - d - 1)%N + 1;
    	ans = (ans%N + N - 1)%N + 1;
    	//printf("x0 = %d, y0 = %d, y00 = %d, z00 = %d, k0 = %d, l0 = %d, y = %d, day = %d\n", x0, y0, y00, z00, k0, l0, y, day);
    	printf("Case %d: the next triple peak occurs in %d days.\n", ++o, ans);
    }
    return 0;
}