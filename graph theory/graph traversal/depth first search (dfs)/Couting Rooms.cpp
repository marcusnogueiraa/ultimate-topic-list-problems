#include <bits/stdc++.h>
 
#define endl '\n'
#define ii pair<int, int>
 
using namespace std;
 
int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};
 
int n, m;
const int MAXS = 1000;
char mat[1000][1000];
 
bool is_valid(int i, int j){
    return i >= 0 && i < n && j >=0 && j < m && mat[i][j] == '.';
}
 
void BFS(int i, int j){
    mat[i][j] = '#';
    queue<ii> q;
    q.push({i, j});
 
    while(!q.empty()){
        ii pos = q.front();
        q.pop();
 
        i = pos.first;
        j = pos.second;
 
        for(int k = 0; k < 4; k++){
            int ni = i + di[k];
            int nj = j + dj[k];
 
            if(is_valid(ni, nj)){
                q.push({ni, nj});
                mat[ni][nj] = '#';
            }
        }
    }
}
 
int main(){
    cin >> n >> m;
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
 
 
    int rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (mat[i][j] == '.'){
                BFS(i, j);
                rooms++;
            }
        }
    }
 
    cout << rooms << endl;
}
