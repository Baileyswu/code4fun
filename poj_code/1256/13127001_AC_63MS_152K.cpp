#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool comp(char  a, char b)
{
 int asc1, asc2;
 
 asc1 = (a >= 'a' && a <= 'z') ? (a - 'a')*2 + 1 : (a - 'A')*2;
 asc2 = (b >= 'a' && b <= 'z') ? (b - 'a')*2 + 1 : (b - 'A')*2;
 
 return asc1 < asc2;
}
void insertSort(char str[], int size)
{
 char tmp;
 int i, j;
 for(i = 1; i < size; i++)
 {
  tmp = str[i];
  j = i - 1;
  while(j >= 0 && comp(tmp, str[j]))
  {
   str[j+1] = str[j];
   j--;
  }
  str[j+1] = tmp;
 }
}
int main()
{
 int total, len;
 char str[13];
 scanf("%d", &total);
 while(total--)
 {
  scanf("%s", str);
  len = strlen(str);
  insertSort(str,len);
  printf("%s\n", str);
  while(next_permutation(str, str+len, comp))
   printf("%s\n", str);
 }
}