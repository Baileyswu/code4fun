/*1. 扩展欧几里得*/
LL extend_Euclid(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1; y = 0;
        return a;
    }
    LL r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}

/*2. 费马小定理*/
#define LL long long
LL poo(LL a, int k, int m){
    LL res = 1;
    while(k){
        if(k & 1LL)
            res = res * a % m;
        k >>= 1;
        a = a*a%m;
    }
    return res;
}

/*3. 打表*/
int rev[N];
void get_rev(){
    rev[1] = 1;
    for(int n = 2;n < N;n++){
        int k = P % n, t = P / n;
        rev[n] = 1LL*(P-t)*rev[k]%P;
    }
}
