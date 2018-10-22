#include<stdio.h>  
struct line{  
    int x1,y1,x2,y2;  
}h[110],v[110];  
int n,hn,vn;  
bool inst(line a,line b){  
    return a.x1<=b.x1&&a.x2>=b.x1&&b.y1<=a.y1&&b.y2>=a.y1;  
}  
int main(){  
    int i,j,k,l,cs,as;  
    int x1,x2,y1,y2,ex;  
    scanf("%d",&cs);  
    while(cs--){  
        hn=vn=0;  
        scanf("%d",&n);  
        for(i=0;i<n;i++){  
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
            if(x1==x2){  
                if(y1>y2){ex=y1;y1=y2;y2=ex;}  
                v[vn].x1=x1;  
                v[vn].y1=y1;  
                v[vn].y2=y2;  
                vn++;  
            }  
            if(y1==y2){  
                if(x1>x2){ex=x1;x1=x2;x2=ex;}  
                h[hn].x1=x1;  
                h[hn].x2=x2;  
                h[hn].y1=y1;  
                hn++;  
            }  
        }  
        as=0;  
        for(i=0;i<hn;i++)  
            for(j=0;j<vn;j++)  
                if(inst(h[i],v[j]))  
                    for(k=i+1;k<hn;k++)  
                        if(inst(h[k],v[j]))  
                            for(l=j+1;l<vn;l++)  
                                if(inst(h[i],v[l]))  
                                    if(inst(h[k],v[l]))  
                                        as++;  
        printf("%d\n",as);  
    }  
    return 0;  
}  
