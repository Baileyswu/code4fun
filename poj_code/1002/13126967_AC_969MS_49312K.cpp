#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int ctoi(char ch)
{
	if(ch=='A' || ch=='B' || ch=='C')
		return 2;
	if(ch=='D' || ch=='E' || ch=='F')
		return 3;
	if(ch=='G' || ch=='H' || ch=='I')
		return 4;
	if(ch=='J' || ch=='K' || ch=='L')
		return 5;
	if(ch=='M' || ch=='N' || ch=='O')
		return 6;
	if(ch=='P' || ch=='R' || ch=='S')
		return 7;
	if(ch=='T' || ch=='U' || ch=='V')
		return 8;
	if(ch=='W' || ch=='X' || ch=='Y')
		return 9;
}

int time[10000000];  
bool vist[10000000]; 
int sort_out[100000]; 

int main(void)
{
	int n;  //号码数
	while(cin>>n)
	{
		memset(time,0,sizeof(time));
		memset(vist,false,sizeof(vist));
		int ps=0;  //sort_out指针
		bool flag=false;  //标记是否出现过重复号码

		/*Input*/

		for(int i=1;i<=n;i++)
		{
			int x=0;
			char s[20];
			cin>>s;
			for(int j=0;s[j]!='\0';j++)
			{
				if(s[j]=='-' || s[j]=='Q' || s[j]=='Z')
					continue;
				else if(s[j]<='9')
					x=x*10+s[j]-'0';
				else if(s[j]<='Z')
					x=x*10+ctoi(s[j]);
			}

			time[x]++;

			if(!vist[x] && time[x]>=2)  //电话号码x重复出现2次以上，则等待输出
			{
				flag=true;
				vist[x]=true;
				sort_out[ps++]=x;
			}
		}
		if(!flag)
			cout<<"No duplicates."<<endl;
		else
		{
			sort(sort_out,sort_out+ps);  //把待输出按字典序排序

			for(int i=0;i<ps;i++)
			{
				cout<<setfill('0')<<setw(3)<<sort_out[i]/10000;
				cout<<'-';
				cout<<setfill('0')<<setw(4)<<sort_out[i]%10000;
				cout<<' '<<time[ sort_out[i] ]<<endl;
			}
		}
	}
	return 0;
}