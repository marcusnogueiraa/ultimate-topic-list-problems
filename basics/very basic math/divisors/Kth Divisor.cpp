#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll kth_divisor(ll n, ll k){
    vector<ll> divisors;
    for(ll i = 1; i * i <= n; i++){
        if (n % i == 0){
            divisors.push_back(i);
            if (n / i != i) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    
    if (divisors.size() < k) return -1;
    else return divisors[k-1];
}

int main(){
    ll n, k;
    cin >> n >> k;
    cout << kth_divisor(n, k) << endl;
}