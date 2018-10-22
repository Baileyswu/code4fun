#include<stdio.h>
#include<string.h>
int main()
{
    char a[15],b[15];
    int i,j,sum=0;
    scanf("%s%s",a,b);
    for(i=0;i<strlen(a);i++)
        for(j=0;j<strlen(b);j++)
            sum+=(a[i]-'0')*(b[j]-'0');
    printf("%d\n",sum);
}
