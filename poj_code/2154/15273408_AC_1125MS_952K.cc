#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL int
#define N 32000
int prim[N], num[N], phi[N];
void et(){
	memset(num, 0, sizeof(num));
	for(int i = 2;i < N;i++)
		for(int j = i*i; j < N;j += i) if(!num[j])
			num[j] = 1;
	int p = 0;
	for(int i = 2;i < N;i++) if(!num[i])
		prim[p++] = i;
	
	memset(phi, 0, sizeof(phi));
	phi[1] = 1;
	for(int i = 2;i < N;i++) if(!phi[i])
		for(int j = i;j < N;j += i){
			if(!phi[j]) phi[j] = j;
			phi[j] = phi[j]/i*(i-1);
		}
}
LL product_mod(LL a, LL b, LL c){
	a %= c; b %= c;
	LL ret = c;
	LL tmp = a;
	while(b){
		if(b & 1){
			ret += tmp;
			if(ret > c) ret -= c;
		}
		tmp <<= 1;
		if(tmp > c) tmp -= c;
		b >>= 1;
	}
	return ret;
}
LL power_mod(LL a, LL n, LL mod){
	LL ret = 1;
	LL tmp = a%mod;
	while(n){
		if(n & 1) ret = product_mod(ret, tmp, mod);
		tmp = product_mod(tmp, tmp, mod);
		n >>= 1;
	}
	return ret;
}
LL euler(LL x){
	if(x < N) return phi[x];
	LL ans = x;
	for(int i = 0;prim[i]*(LL)prim[i] <= x;i++){
		if(x % prim[i] == 0){
			ans -= ans/prim[i];
			while(x % prim[i] == 0) x /= prim[i];
		}
	}
	if(x > 1) ans -= ans/x;
	return ans;
}
LL polya_rot(LL p, LL n, LL mod){
	LL i, tp = sqrt(n), sum = 0;
	if(tp * tp == n){
		sum = power_mod(p, tp-1, mod)*euler(tp)%mod;
		tp--;
	}
	for(int i = 1;i <= tp;i++)
		if(n%i == 0){
			sum += product_mod(power_mod(p, i-1, mod), euler(n/i), mod);
			sum += product_mod(power_mod(p, n/i-1, mod), euler(i), mod);
			sum %= mod;
		}
	return sum;
}
int main()
{
	et();
	int T;
	scanf("%d", &T);
	while(T--){
		LL n, mod;
		scanf("%d%d", &n, &mod);
		LL ans = polya_rot(n, n, mod);
		printf("%d\n", ans);
	}
	return 0;
}