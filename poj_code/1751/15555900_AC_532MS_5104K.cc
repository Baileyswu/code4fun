#include<iostream>  
 #include<cstring>  
 #include<algorithm>  
 #include<cstdlib>  
 #include<cmath>  
 using namespace std; 
 const int MAX_SIZE=800; 
 struct Node 
 { 
     int u,v; 
     double w; 
     bool operator < (const Node a)const 
     { 
         return w<a.w; 
     }; 
 }edge[MAX_SIZE*MAX_SIZE/2]; 
 struct point 
 { 
     int x,y; 
 }a[MAX_SIZE]; 
 int flag[MAX_SIZE],num,n,m; 
  
 int getflag(int u) 
 { 
     if(flag[u]!=u) 
         flag[u]=getflag(flag[u]); 
     return flag[u]; 
 } 
 void execute() 
 { 
     int i,j; 
     for(i=1;i<=n;i++) 
     { 
         for(j=i+1;j<=n;j++) 
             if(getflag(i)!=getflag(j)) 
             { 
                 edge[num].u=i; 
                 edge[num].v=j; 
                 edge[num++].w=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)); 
             } 
     } 
     sort(edge,edge+num); 
     for(i=0;i<num;i++) 
         if(getflag(edge[i].u)!=getflag(edge[i].v)) 
         { 
             flag[getflag(edge[i].u)]=flag[getflag(edge[i].v)]; 
             cout<<edge[i].u<<' '<<edge[i].v<<endl; 
         } 
 } 
 int main() 
 { 
     cin>>n; 
     int u,v; 
     int i; 
     for(i=1;i<=n;i++) 
         cin>>a[i].x>>a[i].y; 
     cin>>m; 
     for(i=1;i<=n+2;i++) 
     flag[i]=i; 
     num=0; 
     while(m--) 
     { 
         cin>>u>>v; 
         flag[getflag(u)]=flag[getflag(v)]; 
     } 
     execute(); 
     return 0; 
 } 