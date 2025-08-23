#include <bits/stdc++.h>
using namespace std;
#define ll long long

void mark(int i, int j, vector<string>& g, int n, int m, int k){
    int d = 1;
    while(i - d > -1 && j - d > -1 && j + d < m){
        char l = g[i-d][j-d], r = g[i-d][j+d];
        if((l == '*' || l == '1') && (r == '*' || r == '1')) d++;
        else break;
    }
    if(d-1 >= k){
        for(int x = 0; x < d; x++){
            g[i-x][j-x] = '1'; g[i-x][j+x] = '1';
        }
    }
}

bool test_case(){
    int n, m, k; cin >> n >> m >> k;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    for(int i = n-1; i > -1; i--){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '*' || g[i][j] == '1'){
                mark(i, j, g, n, m, k);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '*'){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}