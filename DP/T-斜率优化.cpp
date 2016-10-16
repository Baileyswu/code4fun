#include <iostream>
#include <cstdio>
using namespace std;

const int N=5000010;
int f[N],q[N],sum[N],a[N],head,tail,n,m;

int DP(int i,int j){
	return f[j]+m+(sum[i]-sum[j])*(sum[i]-sum[j]);
}

int UP(int j,int k){//yj-yk
	return f[j]+sum[j]*sum[j]-(f[k]+sum[k]*sum[k]);
}

int DOWN (int j,int k){//xj-xk
	return 2*(sum[j]-sum[k])
}

int main (){
	freopen ("a.in","r",stdin);
	freopen ("a.out","w",stdout);
	int i;
	while (~scanf ("%d%d",&n,&m)){
		for (i=1;i<=n;i++)
			scanf ("%d",&a[i]);
		sum[0]=f[0]=0;
		for (i=1;i<=n;i++)
			sum[i]=sum[i-1]+a[i];
		head=tail=0;
		q[tail++]=0;
		for (i=1;i<=n;i++){
			while (head+1<tail&&UP(q[head+1],q[head])<=sum[i]*DOWN(q[head+1],q[head]))//找到最优的切点
				head++;
			f[i]=DP(i,q[head]);
			while (head+1<tail&&UP(i,q[tail-1])*DOWN(q[tail-1],q[tail-2])<=UP(q[tail-1],q[tail-2])*DOWN(i,q[tail-1]))//i加进去之后删去队尾的上凸点
				tail--;
			q[tail++]=i;
		}
		printf("%d\n",f[n]);
	}	
	return 0;
}
