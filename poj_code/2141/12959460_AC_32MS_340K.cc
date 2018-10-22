#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    char rev[30],code[100];
    int l,i;
    while(gets(rev))
    {
        gets(code);
        l=strlen(code);
        for(i=0;i<l;i++)
        {
            if(code[i]!=' '&&code[i]>'Z')
                code[i]=rev[code[i]-'a'];
            else if(code[i]!=' '&&code[i]<'a')
                code[i]=rev[code[i]+32-'a']-32;
        }
        P("%s\n",code);
    }
    R 0;
}
