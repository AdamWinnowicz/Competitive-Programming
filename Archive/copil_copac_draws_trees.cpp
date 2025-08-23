// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
/*

    use dfs to find the furthest node from vertex one
    
    if we go from a lower numbered edge to a higher one, the distance doesn't increase

*/

void dfs(int i, int u, int par, vector<vector<pair<int,int>>>& adj, int curr_dist, int& ans){
    if(curr_dist > ans){
        ans = curr_dist;
    }
    for(pair<int,int> p : adj[u]){
        int v = p.first, j = p.second;
        if(v != par){
            if(j < i) curr_dist++;
            dfs(j, v, u, adj, curr_dist, ans);
            if(j < i) curr_dist--;
        }
            
    }
}

void solve(){
    int n; cin >> n;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    int ans = 0;
    dfs(n, 1, -1, adj, 0, ans);
    cout << ans << '\n';
}

int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
}
