LL factor(LL n) {
	LL ret = 1;
	for(int i = 0;i < pn;i++) {
		LL t = 1;
		while(n % prim[i] == 0) {
			t++;
			n /= prim[i];
		}
		ret *= t;
	}
	if(n != 1)
		ret *= 2;
	return ret;
}