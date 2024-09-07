# include <bits/stdc++.h>

using namespace std;

int main(){
    int days; cin >> days;
    
    int y = days / 365;
    days = days % 365;
    int m = days / 30;
    days = days % 30;
    
    cout << y << " years" << endl;
    cout << m << " months" << endl;
    cout << days << " days" << endl;
}