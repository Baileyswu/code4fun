#include<stdio.h>
#include<string.h>
int main()
{
	char a[1005];
	int i,j,l,c;
	while(gets(a))
	{
	    c=0;
		l=strlen(a);
		for(i=0;i<l-2;i++)
			if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
			{
				a[i]='w',a[i+1]='e';
				for(j=i+2;j<l-1;j++)
					a[j]=a[j+1];
                c++;
			}
        for(i=0;i<l-c;i++)
            printf("%c",a[i]);
        printf("\n");
	}

}
