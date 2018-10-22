#include
#include
#include
using namespace std;
char a[101];
int main()
{
    scanf("%s",&a[1]);
    int ans=0,tmp;
    for(int i=1;i<=10;i++)
    {
        if(a[i]=='?')
        tmp=i;
        else if(a[i]!='X')
        ans+=(a[i]-'0')*(11-i);
        else
        ans+=(11-i)*10;
    }
    for(int i=0;i<=9;i++)
    if((ans+i*(11-tmp))==0)
    {
        if(i==10)
        printf("X\n");
        else
        printf("%d\n",i);
        return(0);
    }
    if((tmp==10)&&((ans+10)==0))
    {
        printf("X\n");
        return(0);
    }
    printf("-1\n");
    return 0;
}