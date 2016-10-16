/*∑ϕ(x)(N/x)(M/x)对欧拉函数求前缀和，使查询更快。*/
LL gao(int n, int m){
    LL re = 0;
    if(n > m) swap(n, m);
    int last;
    for(int i = 1;i <= n;i = last+1){
        last = min(n/(n/i), m/(m/i));
        re += 1LL*(n/i)*(m/i)*(sum[last]-sum[i-1]);
    }
    return re;
}
