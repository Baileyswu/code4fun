#include <stdio.h>
#include <string.h>
int main()
{
    char str[200], ans[200];
    while(gets(str) && str[0] != '#')
    {
        int len = strlen(str);
        int j = 0;
        for(int i = 0;i < len;i++)
        {
            if(str[i] == ' ')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '0';
            }
            else if(str[i] == '!')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '1';
            }
            else if(str[i] == '$')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '4';
            }
            else if(str[i] == '%')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '5';
            }
            else if(str[i] == '(')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '8';
            }
            else if(str[i] == ')')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = '9';
            }
            else if(str[i] == '*')
            {
                ans[j++] = '%';
                ans[j++] = '2';
                ans[j++] = 'a';
            }
            else
                ans[j++] = str[i];
        }
        ans[j++] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}