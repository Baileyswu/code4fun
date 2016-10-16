#include <iostream>
#include <sstream>
using namespace std;
int main(){
    string line, str;
    while(getline(cin, line)){
        istringstream sm(line);
        while(sm >> str)
            cout << str << endl;
    }
    return 0;
}
