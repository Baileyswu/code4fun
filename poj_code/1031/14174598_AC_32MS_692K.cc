#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define PI 3.1415926
double Angle( double x0, double y0, double x1, double y1 ){
     double a= atan2(y0,x0);
     double b= atan2(y1,x1);
     if( b-a> PI ) a+= 2*PI;    //将夹角映射到-PI~PI之间
     if( a-b> PI ) b+= 2*PI;
     return a-b;
}

int main(){
    double h, k, x[101], y[101], max= 0, min= 0, sum= 0;
    int n, i;
    scanf("%lf%lf%d",&k,&h,&n);
    for( i= 0; i< n; i++ )
        scanf("%lf%lf",&x[i],&y[i]);
    x[n]= x[0], y[n]= y[0];
    for( i= 0; i< n; i++ ){      //精髓啊
        sum+= Angle(x[i],y[i],x[i+1],y[i+1]);
        if( sum< min )    min= sum;
        if( sum> max )    max= sum;
        if( max-min>= 2*PI ){
            max= min+ 2*PI;
            break;
        }
    }
    printf("%.2f\n",(max-min)*k*h);
    return 0;
}