void init (){
     int i;
     for (i=1;i<=n;i++){
         scanf ("%d",&a[i].x);
         f[i][0]=1;
     }
}
void pre (){
     int i,j,l,last;
     last=a[1].x;l=1;
     a[n+1].x=a[n].x-1;
     for (i=1;i<=n+1;i++){
         if (a[i].x==last)continue;
         else {
              for (j=l;j<i;j++){
                  a[j].l=l;
                  a[j].r=i-1;
              }
              last=a[i].x;
              l=i;
         }
     }
     
}

void work (){
     int i,j,t,u,k,ll,rr;
     k=int(log (double(n))/log(2.0));
     for (j=1;j<=k;j++)
         for (i=1;i<=n;i++){
             u=int(i+pow (2.0,j)-1);
             if (u>n)break;
             t=int(i+pow (2.0,j-1));
             f[i][j]=max(f[i][j-1],f[t][j-1]);
             if (a[t-1].x==a[t].x){
                ll=max (i,a[t].l);
                rr=min (u,a[t].r);
                if (rr-ll+1>f[i][j])f[i][j]=rr-ll+1;
             }
         }
}
