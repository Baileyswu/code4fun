#include <cstdio>
#include <iostream>
#include <cstring>
int main()
{
  int A, a, B, b, p;
  while(~scanf("%d%d%d%d%d", &A, &a, &B, &b, &p))
  {
    if((p >= B && b >= A) || (A+B <= p) || (p >= A && a >= B))
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}