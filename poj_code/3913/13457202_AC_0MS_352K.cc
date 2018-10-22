#include <stdio.h>
#include <stdlib.h>
int main()
{
int t, a, b, c, ans;
scanf("%d", &t);
printf("Gnomes:\n");
while(t--)
{
scanf("%d%d%d", &a, &b, &c);
ans = ((a-b)/abs(a-b))*((b-c)/abs(b-c));
if(ans>0)
printf("Ordered\n");
else
printf("Unordered\n");
}
return 0;
}