#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		int n, q; cin >> n >> q;
		vector<int> vet(n), prefix(n+1);
		prefix[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> vet[i-1];
			prefix[i] = prefix[i-1] + vet[i-1];
		}
		
		int a, b, k;
		for(int i = 0; i < q; i++){
			cin >> a >> b >> k;
			int res = prefix[n] - prefix[b] + prefix[a-1] + k*(b-a+1);
			if (res & 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}