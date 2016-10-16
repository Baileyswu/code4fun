#include<iostream>
using namespace std;
int n,m,ans;
void init(void)
{
	freopen("bead.in","r",stdin);
	freopen("bead.out","w",stdout);
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int ksm(int x,int y)
{
	int i,j=x,k=1;
	while(y)
	{
		if(y%2)
			k=k*j;
		j=j*j;
		y/=2;
	}
	return k;
}
void work(void)
{
	int i;
	ans=0;
	for(i=1;i<=m;i++)
	{
		//cout<<n<<' '<<gcd(i,m)<<endl;
		ans+=ksm(n,gcd(i,m));
	}
	//cout<<ans<<endl;
	
//	cout<<ans<<endl;
	if(m%2==0)
	{
		ans+=m/2*ksm(n,(m+1)/2);
		ans+=m/2*ksm(n,m/2+1);
		//cout<<ans<<endl;
		ans/=m*2;
	}
	else
	{
		ans+=m*ksm(n,(m+1)/2);
		//cout<<ans<<endl;
		ans/=m*2;
	}
	//cout<<ans<<endl;
	cout<<ans<<endl;
}
int main(void)
{
	init();
	cin>>n>>m;
	while(n||m)
	{
		work();
		cin>>n>>m;
	}
	return 0;
}
