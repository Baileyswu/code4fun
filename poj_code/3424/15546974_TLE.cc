#include<cstdio>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

set<string> s;
set<string>::iterator it;

bool check(int x, int y) //判断是否落入窗口
{
    if(x >= 0 && x < 300 && y >= 0 && y < 300) return true;
    else return false;
}

void solve(int n, int x1, int y1, int x2, int y2, int p[][2])
{
    char ret[110];
    ret[n] = '\0';
    int i, j, k, dx, dy;
    for(i = x2 - 300; i <= x1 + 300; i++) //注意坐标原点的范围
    {
        for(j = y2 - 300; j <= y1 + 300; j++)
        {
            bool flag = true;
            for(k = 0; k < n; k++)
            {
                dx = p[k][0] - i;
                dy = p[k][1] - j;
                if(!check(dx, dy)) { flag = false; break; }
                ret[k] = '1' + dx / 100 + dy / 100 * 3;
            }
            if(flag) s.insert(string(ret));
        }
    }
}

int main()
{
    int n;
    int x1, x2, y1, y2;
    int p[101][2];
    while(scanf("%d",&n) != EOF)
    {
          s.clear();
          x1 = y1 = 999999;
          x2 = y2 = -999999;
          for(int i = 0; i < n; i++)
          {
              scanf("%d%d",&p[i][0],&p[i][1]);
              p[i][1] = -p[i][1]; //纵坐标取反
              x1 = min(x1, p[i][0]);
              y1 = min(y1, p[i][1]);
              x2 = max(x2, p[i][0]);
              y2 = max(y2, p[i][1]);
          }

          solve(n, x1, y1, x2, y2, p);
          if(s.size() == 0) { puts("NONE\n"); continue;}
          for(it = s.begin(); it != s.end(); it++)
              printf("%s\n",it->c_str());
    }
    return 0;
}
