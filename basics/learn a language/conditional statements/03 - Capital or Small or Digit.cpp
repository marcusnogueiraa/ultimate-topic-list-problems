#include <bits/stdc++.h>

using namespace std;

int main(){
    char c;
    cin >> c;
    
    if (c <= '9') cout << "IS DIGIT" << endl;
    else {
        cout << "ALPHA" << endl;
        if (c >= 'a' && c <= 'z') cout << "IS SMALL" << endl;
        else cout << "IS CAPITAL" << endl;
    }
}