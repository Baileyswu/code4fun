#include <stdio.h>
#include <math.h>
#include <string.h>
int abs(int x)
{
    if(x<0)x=0-x;
    return x;
}
int main()
{
   int nCases,i;
   scanf("%d",&nCases);
   int x,y;
   for(i=0;i<nCases;i++)
   {
       char begin[5],end[5];
       scanf("%s%s",begin,end);
       x=abs(begin[0]-end[0]);
       y=abs(begin[1]-end[1]);
       if(x==0&&y==0)//起始位置相同的情况
           printf("0 0 0 0\n");
       else
       {
           if(x<y)          //王的步数
               printf("%d",y);
           else
               printf("%d",x);
           if(x==0||y==0||x==y)//后的步数
               printf(" 1");
           else
               printf(" 2");
           if(x==0||y==0)//车的步数
               printf(" 1");
           else
               printf(" 2");
           if(abs(x-y)%2!=0)//象的步数
               printf(" Inf\n");
           else if(x==y)
               printf(" 1\n");
           else
               printf(" 2\n");
       }
   }
   return 0;
}
