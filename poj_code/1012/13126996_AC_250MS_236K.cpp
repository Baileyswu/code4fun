//Memory Time
//184K   250MS 

#include<iostream>
using namespace std;

int main(void)
{
	int Joseph[14]={0};  //打表，保存各个k值对应的m值

	int k;
	while(cin>>k)
	{
		if(!k)
			break;

		if(Joseph[k])
		{
			cout<<Joseph[k]<<endl;
			continue;
		}

		int n=2*k;  //总人数
		int ans[30]={0};  //第i轮杀掉 对应当前轮的编号为ans[i]的人
		                  //PS:每一轮都以报数为“1”的人开始重新编号

		int m=1;    //所求的最少的报数
		for(int i=1;i<=k;i++)  //轮数
		{
			ans[i]=(ans[i-1]+m-1)%(n-i+1);   //n-i为剩余的人数
			if(ans[i]<k)  //把好人杀掉了,m值不是所求
			{
				i=0;
				m++;  //枚举m值
			}
		}
		Joseph[k]=m;
		cout<<m<<endl;
	}
	return 0;
}