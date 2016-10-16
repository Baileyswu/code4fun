#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;

const int N=40000;

int n,P;
int prim[N],p_num;
bool flag[N];

void prime()//用筛法求质数 
{int i,j;
 memset(flag,true,sizeof(flag));
 for(i=2;i<N;i++)
   if(flag[i])
     for(j=i*i;j<N;j+=i)
       flag[j] = false;
 p_num = 0;
 for(i=2;i<N;i++)
   if(flag[i]) prim[++p_num]=i;
}

int phi(int x)//求欧拉函数
{int i,j;
 int num=x;
 for(i=1;prim[i]*prim[i]<=x;i++)
   if(x%prim[i]==0)
     {num=(num/prim[i])*(prim[i]-1);
      while (x%prim[i]==0)
        x=x/prim[i];
     }
 if(x!=1) num=(num/x)*(x-1);
 return num%P;
}

int exp(int x, int y)//求x的y次方mod p
{long long i;
 if (y==0) return 1;
 if (y==1) return x%P;
 i=exp(x,y/2);
 i=(i*i)%P;
 if (y%2==1) i=i*x;
 return i%P;
}

void work()
{int i,j,k;
 int ans=0;
 for (i=1;i*i<=n;i++)//枚举长度
   if (i*i==n)
     {ans+=phi(i)*exp(n,i-1);
      ans=ans%P;
     }
   else
     if (n%i==0) //有长度为i的循环,就会有长度为n/i的循环
       {ans+=phi(i)*exp(n,n/i-1);//枚举循环长度i,找出相应的i的个数:gcd(n,i)=n/i
        ans+=phi(n/i)*exp(n,i-1);
        ans=ans%P;
       }
 cout<<ans<<endl;
} 

int main()
{freopen("color.in","r",stdin);
 freopen("color.out","w",stdout);
 int cases;
 scanf("%d",&cases);
 prime();
 while(cases--)
   {scanf("%d%d",&n,&P);
    work(); 
   }
 return 0;
}
