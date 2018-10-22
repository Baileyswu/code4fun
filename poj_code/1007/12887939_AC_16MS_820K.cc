#include<stdio.h>
int main()
{
	int n,m,i,j,k,a[1000],min,max;
	char str[1000][500];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
	    a[i]=0;
        scanf("%s",&str[i]);
        for(j=0;j<n;j++)
            for(k=j+1;k<n;k++)
                if(str[i][k]<str[i][j])
                    a[i]++;
	}
	min=a[0],max=a[0];
	for(i=0;i<m;i++){
        if(a[i]>max)max=a[i];
        else if(a[i]<min)min=a[i];
    }
    for(k=min;k<=max;k++)
        for(i=0;i<m;i++)
            if(a[i]==k)
                printf("%s\n",str[i]);
	return 0;
}
