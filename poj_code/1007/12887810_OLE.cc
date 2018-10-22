#include<stdio.h>
int main()
{
	int n,m,i,j,k,a[100],t;
	char str[100][50],ex[50];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
	    a[i]=0;
        scanf("%s",&str[i]);
        for(j=0;j<n;j++)
            for(k=j+1;k<n;k++)
                if(str[i][k]<str[i][j])
                    a[i]++;
	}
	for(i=0;i<m;i++)
        for(j=i+1;j<m;j++)
            if(a[j]<a[i]){
                t=a[j];a[j]=a[i];a[i]=t;
                for(k=0;k<n;k++){
                    ex[k]=str[j][k];
                    str[j][k]=str[i][k];
                    str[i][k]=ex[k];
                }
            }
    for(i=0;i<m;i++){
        printf("%s",str[i]);
        printf("\n");
        }
	return 0;
}
