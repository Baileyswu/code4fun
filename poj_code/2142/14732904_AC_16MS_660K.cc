/*--------------------------------------------
 * File Name: POJ 2142
 * Author: Baileys Wu
 * Mail: wulidan0530@live.com
 * Created Time: 2015-09-17 16:16:04
--------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
#define inf 2000000000
int extend_Euclid(int a, int b, int &x, int &y){
    if(b==0){
   		x = 1; y = 0;
    	return a;
    }
    int r = extend_Euclid(b, a%b, y, x);
    y -= a/b*x;
    return r;
}
int equation(int a, int b, int c)
{
    int x, y;
    int g = extend_Euclid(a, b, x, y);
    if(c % g)
        return 0;    //表示无解
    int ran = b/g, sum = inf, ak = inf;
    x = (x*c/g%ran+ran)%ran;
    int X = x, Y, ansx, ansy;
    for(int k = 0;;k++)
    {
        Y = (c-a*X)/b;
        //printf("%d %d %d %d %d %d\n", k, X, Y, abs(X)+abs(Y), ak, sum);
        if(abs(X)+abs(Y) < ak || (abs(X)+abs(Y) == ak && a*abs(X) + b*abs(Y) < sum))
        {
        	ansx = abs(X); ansy = abs(Y);
        	ak = abs(X) + abs(Y);
        	sum = a*abs(X) + b*abs(Y);
        }
        X += b/g;
        if(Y < 0)
        	break;
    }
    //printf("----------\n");
    X = x;
    for(int k = 0;;k++)
    {
        Y = (c-a*X)/b;
        //printf("%d %d %d %d %d %d\n", k, X, Y, abs(X)+abs(Y), ak, sum);
        if(abs(X)+abs(Y) < ak || (abs(X)+abs(Y) == ak && a*abs(X) + b*abs(Y) < sum))
        {
        	ak = abs(X) + abs(Y);
        	ansx = abs(X); ansy = abs(Y);
        	sum = a*abs(X) + b*abs(Y);
        }
        if(X < 0)
        	break;
        X -= b/g;
    }
    printf("%d %d\n", ansx, ansy);
}
int main()
{
	int a, b, c;
	while(~scanf("%d%d%d", &a, &b, &c))
	{
		if(!a && !b && !c)
			break;
		equation(a, b, c);
	}
	return 0;
}