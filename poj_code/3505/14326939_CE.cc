#include <iostream>  
#include <algorithm>  
#include <memory.h>
#include <cstdio>
#include <cmath>  
using namespace std;  
  
struct Info//储存车的位置   
{  
     int x;  
     int y;  
}pos[2600];  
  
int move[60];//记录每次升降机的每一次动作位置，为下一次的动作位置计算作准备！   
  
int main()  
{  
    int tc, i, j, h, l, tmp, cards, ans, dis;  
    cin >> tc;  
    while (tc--)  
    {  
          cin >> h >> l;  
          cards = ans = 0;  
          //输入的处理   
          for (i = 0; i < h; i++)  
            for (j = 0; j < l; j++)  
            {  
                cin >> tmp;  
                if (tmp != -1)  
                {  
                    pos[tmp].x = i;  
                    pos[tmp].y = j;  
                    cards++;  
                }  
            }  
          memset(move, 0, sizeof(move));  
          //对每一次拿车的时间的计算   
          for (i = 1; i <= cards; i++)  
          {  
              ans += pos[i].x * 20;  
              //注意这个，因为传输带可以顺时针，也可以逆时针，找出小的距离值   
              dis = min(abs(pos[i].y-move[pos[i].x]), l - abs(pos[i].y-move[pos[i].x]));  
              //cout << dis << " " ;
              ans += dis * 5;  
              move[pos[i].x] = pos[i].y;//记录了传输带目前的位置   
             // cout << "temp" << ans << endl; 
          }  
          cout << ans << endl;  
    }  
}  