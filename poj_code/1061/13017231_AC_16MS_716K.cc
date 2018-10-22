#include <iostream>
using namespace std;

__int64 t,p;

__int64 euclid(__int64 a,__int64 b){
	if(b==0)
		return a;
	else
		return euclid(b,a%b);
}

void extended_euclid(__int64 a,__int64 b){
	if(b==0){
		t=1;
		p=0;
	}
	else{
		__int64 temp;
		extended_euclid(b,a%b);
		temp=t-a/b*p;
		t=p;
		p=temp;
	}
}

int main(){
	__int64 x,y,n,m,L,gcd;
	cin>>x>>y>>m>>n>>L;
	if (m==n){
		cout<<"Impossible"<<endl;
		return 0;
	}
	__int64 a,b,c,c1;
	a=n-m;
	b=L;
	c=x-y;
	gcd=euclid(a,b);
	c1=c%gcd;
	if (c1!=0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	c/=gcd;
	a/=gcd;
	b/=gcd;
	extended_euclid(a,b);
	t*=c;
	p*=c;
	t=(t%b+b)%b;
	cout<<t<<endl;
	return 0;
}
