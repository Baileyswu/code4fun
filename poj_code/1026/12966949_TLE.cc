#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int n,k,i,l,a[205];
    char code[205],answer[205];
    while((S("%d",&n))!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
            S("%d",&a[i]);
        while((S("%d",&k))!=EOF&&k!=0)
        {
            getchar();
            gets(code);
            l=strlen(code);
            while(l<n)
            {
                code[l]=' ';
                l++;
            }
            while(k--)
            {
                for(i=0;i<n;i++)
                    answer[a[i]-1]=code[i];
                for(i=0;i<n;i++)
                    code[i]=answer[i];
            }
            P("%s\n",answer);
        }
    }
    R 0;
}
