#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int l, r;

void diameter_dfs(int par, int u, vector<vector<int>>& adj, int&dist, int curr_dist, int& furthest_node){
    if(curr_dist > dist){
        dist = curr_dist;
        furthest_node = u;
    }
    curr_dist++;
    for(int v : adj[u]){
        if(v != par){
            diameter_dfs(u, v, adj, dist, curr_dist, furthest_node);
        }
    }
}

void tree_diameter(vector<vector<int>>& adj){
    int dist = 0, furthest_node = 1;
    diameter_dfs(-1, 1, adj, dist, 0, furthest_node);
    l = furthest_node;
    dist = 0;
    diameter_dfs(-1, furthest_node, adj, dist, 0, furthest_node);
    r = furthest_node;
}

void traverse(int par, int u, vector<vector<int>>& adj, vector<int>& max_dist, int curr_dist){
    max_dist[u] = max(max_dist[u], curr_dist);
    curr_dist++;
    for(int v : adj[u]){
        if(v != par){
            traverse(u, v, adj, max_dist, curr_dist);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    tree_diameter(adj);
    vector<int> max_dist(n + 1);
    traverse(-1, l, adj, max_dist, 0);
    traverse(-1, r, adj, max_dist, 0);
    for(int i = 1; i <= n; i++){
        cout << max_dist[i] << (i == n ? "\n" : " ");
    }

    return 0;
}
