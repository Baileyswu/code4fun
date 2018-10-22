#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#define P 3.141592653589793
using namespace std;
int main()
{
	double x1,y1,x2,y2,x3,y3,len1,len2,len3,cosine,sine,r,s;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		len1=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
		len2=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
		len3=sqrt(pow(x3-x1,2)+pow(y3-y1,2));
		cosine=(pow(len2,2)+pow(len3,2)-pow(len1,2))/2/len2/len3;
		sine=sqrt(1-pow(cosine,2));
		r=len1/2/sine;
		s=P*r*2;
		cout<<fixed<<setprecision(2)<<s<<endl;
	}
	return 0;
}