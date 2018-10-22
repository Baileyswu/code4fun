#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int equal(int a[],int n)
{
    int b[n],c[n],num[n],i,count=0,v=1;
    for(i=0;i<n;i++)
    {c[i]=a[i];num[i]=a[i];}
    while(v)
    {
        for(i=0;i<n;i++)
            b[num[i]-1]=c[i];
        for(i=0;i<n;i++)
            c[i]=b[i];
        i=0;
        while(a[i]==b[i]&&i<n)
            i++;
        if(i==n)
        {
            v=0;
            break;
        }
        count++;
    }
    R count+1;
}
int main()
{
    int n,k,i,l,a[205],T;
    char code[205],answer[205];
    while((S("%d",&n))!=EOF&&n!=0)
    {
        for(i=0;i<n;i++)
            S("%d",&a[i]);
        T=equal(a,n);
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
            k=k%T;
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
