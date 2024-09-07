#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
ll g;
ll tot = 0;
vector<vector<ll>> G;
vector<bool> hasCat;

void dfs(int v, ll cats, int parent){
    if (hasCat[v]) cats++;
    else cats = 0;

    if (cats > g) return;
    
    if (v != 0 && G[v].size() == 1) {
        tot++;
        return;
    }
    
    for(auto u : G[v]){
        if (u != parent) dfs(u, cats, v);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> g;

    G.assign(n, vector<ll>());
    hasCat.assign(n, false);

    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        hasCat[i] = (c == 1); 
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;

        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0,0,-1);
    cout << tot << endl;

}