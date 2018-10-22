#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //cout << "Hello, World!\n";
    int n,m;
    cin >> n >> m;
    
    bool flag = true;
    
    for (int i=1;i<= m; i++){
    
        int a,b;
        cin >> a >> b;
        
        if(!(a == b-1 || b == a-1 || (a == 0 && b == n-1) || (a == n-1 && b == 0)))
           flag = false;
    }
           
    if(flag) cout << "panda is telling the truth...\n";
           else cout << "the evil panda is lying again" << endl;
        
    
    return 0;
}
