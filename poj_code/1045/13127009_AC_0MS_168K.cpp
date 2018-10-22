#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
int n;
double vs, r, c, w;
int main()
{
    //freopen("t.txt", "r", stdin);
    scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
    while (n--)
    {
        scanf("%lf", &w);
        printf("%.3f\n", r * c * w * vs * sqrt(1/(r*r*c*c*w*w + 1)));
    }
    return 0;
}