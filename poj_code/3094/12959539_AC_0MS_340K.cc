#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    char code[260];
    int i,l,s;
    while(gets(code)&&code[0]!='#')
    {
        l=strlen(code),s=0;
        for(i=0;i<l;i++)
        {
            if(code[i]!=' ')
                s+=(code[i]-'A'+1)*(i+1);
        }
        P("%d\n",s);
    }
    R 0;
}
