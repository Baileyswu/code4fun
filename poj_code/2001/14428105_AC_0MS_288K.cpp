#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

struct node
{
    int cnt;
    short al[26];
};

int ptr=0;
char s[1001][21];
node word[20010];

void Insert(char*s)
{
    int now=0; 
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(word[now].al[s[i]-'a']==0)
        {
            word[now].al[s[i]-'a']=++ptr;
            now=ptr;
        }
        else now=word[now].al[s[i]-'a'];
        word[now].cnt++;
    }
}

void print(char*s)
{
    int now=0; 
    int len=strlen(s);
    printf("%s ",s);
    for(int i=0;i<len;i++)
    {
        now=word[now].al[s[i]-'a'];
        printf("%c",s[i]);
        if(word[now].cnt==1) break;
    }
    printf("\n");
}
                                                                         
int main()
{
    int i=0;
    while(gets(s[i])&&s[i][0]!='\0')
        Insert(s[i++]);
    for(int ii=0;ii<i;ii++)
        print(s[ii]);
    return 0;
}
