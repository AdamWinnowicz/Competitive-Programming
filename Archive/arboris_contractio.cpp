#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // find number of leaves
    // consider the number of adj vertices that are leaves(their only adj vertice is the parent)
    set<int> leaves;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 1) leaves.insert(i);
    }
    int m = leaves.size();
    int ans = m;
    for(int i = 1; i <= n; i++){
        int adj_leaves = 0;
        for(int v : adj[i]){
            if(leaves.find(v) != leaves.end())
                adj_leaves++;
        }
        if(leaves.find(i) != leaves.end()) adj_leaves++;
        ans = min(ans, m - adj_leaves);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}