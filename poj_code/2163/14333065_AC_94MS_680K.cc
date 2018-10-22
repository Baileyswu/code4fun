#include <stdio.h>
int main()
{
    int m, n, k, i, j,l,r;
    double pm[10010], pn[10010];
    double eps=1e-9;
    double sum[10010],a[10010];
    scanf("%d %d %d", &m, &n, &k);
    sum[0]=0;
    for (i = 1; i <= k; i++){
        scanf("%lf", &a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    for (i = m; i <= k; i++) 
    	pm[i] = (double)(sum[i]-sum[i-m])/m;
    for (i = n; i <= k; i++) 
    	pn[i] = (double)(sum[i]-sum[i-n])/ n;
    if(pm[n] - pn[n] > eps) 
    	printf("BUY ON DAY %d\n", n);
    else if(pn[n] - pm[n] > eps) 
    	printf("SELL ON DAY %d\n", n);
    for(i = n+1; i <= k; i++) 
    	if(pm[i] - pn[i] > eps && pn[i-1] - pm[i-1] > eps) 
    		printf("BUY ON DAY %d\n", i);
        else if(pn[i] - pm[i] > eps && pm[i-1] - pn[i-1] > eps) 
    		printf("SELL ON DAY %d\n", i);
    return 0;
}