#include <cstdio>
#include <iostream>
#include <cstring>
int main()
{
  int n;
  char pre[105], str1[105], str2[105];
  scanf("%d", &n);
  while(n--)
  {
    scanf("%s%s%s", pre, str1, str2);
    int a = strlen(pre), b = strlen(str1), p = 0, i = 0;
    while(p < a && i < b)
    {
      while(i < b)
      {
        if(pre[p] == str1[i] || pre[p] == str2[i] || str1[i] == '*')
        {
          p++, i++;
          break;
        }
        i++;
      }
    }
    if(p == a)
      printf("win\n");
    else
      printf("lose\n");
  }
  return 0;
}