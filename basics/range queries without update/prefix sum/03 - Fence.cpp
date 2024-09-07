#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> fences(n);
    vector<int> ps(n+1);
    ps[0] = 0;

    for(int i = 0; i < n; i++) cin >> fences[i];

    for(int i = 0; i < n; i++)
        ps[i+1] = ps[i] + fences[i]; 

    
    int minIndex = 0;
    int minHeight = INT_MAX;
    for(int i = 0; i < n-k+1; i++){
        int height = ps[i+k] - ps[i];
        if (height < minHeight){
            minIndex = i;
            minHeight = height;
        }
    }

    cout << minIndex+1 << endl;
}