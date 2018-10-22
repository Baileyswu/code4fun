#include <cstdio>
#include <iostream>
#include <cstring>
int main()
{
  int A, a, B, b, p;
  while(~scanf("%d%d%d%d%d", &A, &a, &B, &b, &p))
  {
    if((p >= A && p >= B) || (A+B <= p))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}