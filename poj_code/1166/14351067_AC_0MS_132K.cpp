// 逆矩阵
#include <cstdio>
#include <cstring>
using namespace std;

int a[9][9]={
{3,2,3,2,2,1,3,1,0,},
{3,3,3,3,3,3,2,0,2,},
{3,2,3,1,2,2,0,1,3,},
{3,3,2,3,3,0,3,3,2,},
{3,2,3,2,1,2,3,2,3,},
{2,3,3,0,3,3,2,3,3,},
{3,1,0,2,2,1,3,2,3,},
{2,0,2,3,3,3,3,3,3,},
{0,1,3,1,2,2,3,2,3,}};
//逆矩阵怎么求！
int x[9];
int res[9];

int main()
{
    for(int i=0;i<9;i++)
    {
        scanf("%d",x+i);
        x[i]=(4-x[i])%4;
    }

    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            res[i]+=a[i][j]*x[j];

    for(int i=0;i<9;i++) while(res[i]%4 && res[i]--)
        printf("%d ",i+1);
    puts("");
}
