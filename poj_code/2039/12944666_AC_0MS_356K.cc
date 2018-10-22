#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int strlen(char str[])
{
    int i,count=0;
    for(i=0;i<255;i++)
    {
        if(str[i]!='\0')
            count++;
        else break;
    }
    R count;
}
int main()
{
    int n,i,j,m;
    char str[205];
    while((S("%d",&n))!=EOF&&n!=0)
    {
        S("%s",str);
        m=strlen(str);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(j%(2*n)==i||j%(2*n)==(2*n-1-i))P("%c",str[j]);
            }
        P("\n");
    }
    R 0;
}
