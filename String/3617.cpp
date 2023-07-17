#include <iostream>
using namespace std;

char s[2020], ans[2020];
int n;

bool check(char *str, int l, int r) {
    if(l > r) return false;
    while(l <= r) {
        if(str[l] < str[r]) return true;
        if(str[r] < str[l]) return false;
        l++;
        r--;
    }
    return false;
}
void outwork(char c, int i) {
    putchar(c);
    if((i%80) == 0) putchar('\n');
}
int main() {
    while(cin >> n){
        for(int i = 0;i < n;i++) {
            getchar(); scanf("%c", &s[i]);
        }
        // cout << "str:" << s << endl;
        int l = 0, r = n-1;
        for(int i = 0;i < n;i++) {
            if(check(s, l, r)) {
                outwork(s[l++], i+1);
            } else 
                outwork(s[r--], i+1);
        }
        outwork('\n', n+1);
    }
    return 0;
}