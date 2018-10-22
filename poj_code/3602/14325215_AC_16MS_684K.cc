#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char table[7][10]={"ffi","ffl","fi","fl","ff","``","\'\'"};
int use[155];
char buf[10005];
int main()
{
	use[' ']=1;
	int ans=0,i;
	while(gets(buf))
	{
		for(char *p=buf;*p;)
		{
			for(i=0;i<7;i++)if(strncmp(table[i],p,strlen(table[i]))==0)break;
			if(i<7)p+=strlen(table[i]);
			else i=*p++;
			if(!use[i]){use[i]=1;ans++;}
		}
	}
	printf("%d\n",ans);
}