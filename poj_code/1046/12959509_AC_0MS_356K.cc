#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    int a[16][3],i,j,x,y,z,pos;
    float d,min;
    for(i=0;i<16;i++)
        for(j=0;j<3;j++)
        {
            S("%d",&a[i][j]);
        }
    while((S("%d%d%d",&x,&y,&z))!=EOF&&x!=-1)
    {
        min=sqrt((a[0][0]-x)*(a[0][0]-x)+(a[0][1]-y)*(a[0][1]-y)+(a[0][2]-z)*(a[0][2]-z));
        pos=0;
        for(i=1;i<16;i++)
        {
            d=sqrt((a[i][0]-x)*(a[i][0]-x)+(a[i][1]-y)*(a[i][1]-y)+(a[i][2]-z)*(a[i][2]-z));
            if(d<min)
            {
                min=d;
                pos=i;
            }
        }
        P("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,a[pos][0],a[pos][1],a[pos][2]);

    }
    R 0;
}
