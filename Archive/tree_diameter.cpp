#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void dfs(int par, int u, vector<vector<int>>& adj, int& dist, int& furthest_node, int curr_dist){
    if(curr_dist > dist){
        dist = curr_dist;
        furthest_node = u;
    }
    curr_dist++;
    for(int v : adj[u]){
        if(v != par){
            dfs(u, v, adj, dist, furthest_node, curr_dist);
        }
    }
}

int tree_diameter(vector<vector<int>>& adj){
    int dist = 0, furthest_node = 1;
    dfs(-1, 1, adj, dist, furthest_node, 0);
    dist = 0;
    dfs(-1, furthest_node, adj, dist, furthest_node, 0);
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << tree_diameter(adj) << '\n';

    return 0;
}