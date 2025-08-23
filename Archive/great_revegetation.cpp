#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> colors(n, 0);
    for(int i = 0; i < n; i++){
        vector<bool> occupied(5);
        for(int neighbor : adj[i+1]){
            occupied[colors[neighbor-1]] = true;
        }
        for(int color = 1; color < 5; color++){
            if(!occupied[color]){
                colors[i] = color;
                break;
            }
        }
    }
    for(int color : colors){
        cout << color;
    }

    return 0;
}