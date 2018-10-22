#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    int i;
    long int sum,m;
    while(scanf("%s",str)&&str[0]!='0')
    {
        m=1,sum=0;
        for(i=strlen(str)-1;i>=0;i--)
        {
            if(str[i]>='5')
                str[i]-=1;
            sum+=m*(str[i]-'0');
            m*=9;
        }
        printf("%s: %ld\n",str,sum);
    }
    return 0;
}
