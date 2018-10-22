#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
queue <long long>ans;
int main()
{
    long long n, i;
    while(cin >> n, n)
    {
        i = 1;
        ans.push(1);
        while((i = ans.front()) % n)
        {
            ans.pop();
            i *= 10;
            ans.push(i);
            i += 1;
            ans.push(i);
        }
        cout << i << endl;
        while(!ans.empty())
            ans.pop();
    }
    return 0;
}