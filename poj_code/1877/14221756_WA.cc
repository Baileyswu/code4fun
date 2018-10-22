#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<vector>
#include<set>
#include<cstring>
#include<math.h>
#include<cstdlib>
#define ESP 1e-6

using namespace std;

int main(){
    int m,n,cs=1,k;
    int a[902];
    while(scanf("%d%d",&m,&n),m&&n){
        printf("Region %d\n",cs++);
        k=m*n;
        int i;
        for(i=0;i<k;++i){
            scanf("%d",&a[i]);
        }
        sort(a,a+k);
        a[k]=(1<<31);
        int water;
        double level=a[0],h,ch;
        scanf("%d",&water);
        for(i=0;i<k;++i){
            h=water/(100.0*(i+1));
            ch=a[i+1]-a[i];
            if(ch<h){//原来这样比也是可以的，ESP白设了。。。
                level+=ch;
                water-=ch*(100.0*(i+1));
            }
            else{
                level+=h;
                break;
            }
        }
        printf("Water level is %.2lf meters.\n",level);
        printf("%.2lf percent of the region is under water.\n\n",++i*100.0/k);
    }
    return 0;
}
