#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

void test_case(){
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    int i = (n-1) / 2, j = (n-1)/2, length = 2, val = 2;
    g[i][j] = 0; g[i][j+1] = 1; i++; j++;
    int di = 0, counter = 0;
    while(val < n*n){
        int x = 0;
        while(x < length){
            g[i][j] = val;
            i += directions[di].first; j += directions[di].second;
            x++; val++;
        }
        counter = (counter + 1) % 2;
        if(counter == 0) length++;
        di = (di + 1) % 4;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << g[i][j] << (j == n-1 ? "\n" : " ");
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}