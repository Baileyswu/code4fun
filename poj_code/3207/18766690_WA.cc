//
//  main.cpp
//  huashida00
//
//  Created by ming on 09/07/2018.
//  Copyright © 2018 ming. All rights reserved.
//

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
        
        if(a==b)
           flag = false;
    }
           
    if(flag) cout << "panda is telling the truth...\n";
           else cout << "the evil panda is lying again" << endl;
        
    
    return 0;
}
