#include<stdio.h>
#include<string.h>
#define S scanf
#define P printf
#define R return
int main()
{
    char str[10],code[205],e[10];
    int i;
    while((S("%s",str))!=EOF&&str[0]=='S')
    {
        getchar();
        gets(code);
        gets(e);
        for(i=0;i<strlen(code);i++)
        {
            if(code[i]>='A'&&code[i]<='E')
                code[i]+=21;
            else if(code[i]>='F'&&code[i]<='Z')
                code[i]-=5;
        }
        P("%s\n",code);
    }

    R 0;
}
