#include <bits/stdc++.h>

using namespace std;

int count_divisors(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if (n % i == 0){
            count++;
            if (n / i != i) count++;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        cout << count_divisors(n) << endl;
    }
}
