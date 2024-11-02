#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;

    vector<ll> nums(n);
    vector<ll> nums_ord(n);
    vector<ll> prefix(n+1);
    vector<ll> prefix_ord(n+1);

    prefix[0] = 0;
    prefix_ord[0] = 0;

    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;

        nums[i] = num;
        nums_ord[i] = num;
    }

    sort(nums_ord.begin(), nums_ord.end());

    for(int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + nums[i];
        prefix_ord[i+1] = prefix_ord[i] + nums_ord[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int op, l, r;
        cin >> op >> l >> r; 

        r--; l--;

        if (op == 1) {
            cout << prefix[r+1] - prefix[l] << endl;
        } else {
            cout << prefix_ord[r+1] - prefix_ord[l] << endl;
        }
    }
}