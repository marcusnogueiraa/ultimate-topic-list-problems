#include <bits/stdc++.h>

using namespace std;

int n, m;
int k = 0, v = 0;
int qk, qv;
const int MAXS = 255;
char mat[MAXS][MAXS];

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

bool isvalid(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '#';
}

void dfs(int i, int j){
  if (mat[i][j] == 'k') qk++;
  else if (mat[i][j] == 'v') qv++;

  mat[i][j] = '#';
  for(int k = 0; k < 4; k++){
    int ni = i + di[k];
    int nj = j + dj[k];

    if (isvalid(ni, nj)){
      dfs(ni, nj);
    }
  }
}

int main(){
  cin.tie(0)->sync_with_stdio(0);  
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> mat[i][j];
      if (mat[i][j] == 'k') k++;
      else if (mat[i][j] == 'v') v++;
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if (mat[i][j] != '#'){ 
        qk = 0, qv = 0;
        dfs(i, j);
        if (qk > qv) v -= qv;
        else k -= qk;
      }
    }
  }

  cout << k << " " << v << endl;
  
}