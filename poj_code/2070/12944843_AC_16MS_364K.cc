#include<stdio.h>
#include<math.h>
#define S scanf
#define P printf
#define R return
int main()
{
    float a;
    int b,c,v;
    typedef struct player
    {
        char name[20];
        float speed;
        int weight;
        int strength;
    }PLY;
    PLY *p,q[3]={{"Wide Receiver",4.5,150,200},
                {"Lineman",6.0,300,500},
                {"Quarterback",5.0,200,300}};
    while((S("%f%d%d",&a,&b,&c))!=EOF&&a!=0)
    {
        v=0;
        for(p=q;p<q+3;p++)
        {
            if(a<=p->speed&&b>=p->weight&&c>=p->strength)
            {
                if(v)P(" ");
                printf("%s",p->name);
                v=1;
            }
        }
        if(v==0)
            P("No positions");
        P("\n");
    }
    R 0;
}
