#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void dfs_component(int u, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, map<int, ll>& locs, bool& ans){
    if(visited[u]) return;
    visited[u] = true;
    for(pair<int,int> info : adj[u]){
        int v = info.first, d = info.second;
        ll needed_loc = locs[u] + d;
        if(locs.find(v) != locs.end()){
            if(needed_loc != locs[v]){
                ans = false;
            }
        }
        locs[v] = needed_loc;
        dfs_component(v, adj, visited, locs, ans);
    }
}

bool test_case(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    vector<bool> visited(n + 1, false);
    bool ans = true;
    for(int i = 0; i < m; i++){
        int a, b, d; cin >> a >> b >> d;
        adj[a].emplace_back(b, d);
        adj[b].emplace_back(a, -1 * d);
    }   
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            map<int, ll> locs;
            locs[i] = 0;
            dfs_component(i, adj, visited, locs, ans);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "YES\n" : "NO\n");
    }

    return 0;
}