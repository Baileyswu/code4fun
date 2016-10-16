#define N 100100
#define LL long long
int num[N], prim[N], phi[N] = {1,1}, mob[N]={1,1};
int pn = 0;
void table(){
    memset(num, -1, sizeof(num));
    for(int i = 2;i < N;i++){
    	if(num[i]) {
    		prim[pn++] = i;
    		phi[i] = i-1;
    		mob[i] = -1;
    	}
    	for(int j = 0;j < pn && 1LL*i*prim[j] < N;j++){
    		if(i % prim[j] == 0){
    			phi[i*prim[j]] = phi[i] * prim[j];
    			num[i*prim[j]] = 0;
    			mob[i*prim[j]] = 0;
    			break;
    		}
    		phi[i*prim[j]] = phi[i] * (prim[j]-1);
    		num[i*prim[j]] = 0;
    		mob[i*prim[j]] = -mob[i];
    	}
    }
}
