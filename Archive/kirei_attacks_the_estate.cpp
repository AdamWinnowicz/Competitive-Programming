#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll node, ll parent, vector<ll>& threat, vector<ll>& min_threat, vector<ll>& visited, const map<ll,vector<ll>>& adj, const vector<ll>& a){
    visited[node] = 1;
    threat[node] = max(a[node-1], a[node-1] - min_threat[parent]);
    min_threat[node] = min(a[node-1], a[node-1] - threat[parent]);
    for(ll val : adj.at(node)){
        if(!visited[val]){
            dfs(val, node, threat, min_threat, visited, adj, a);
        }
    }
}

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    map<ll, vector<ll>> adj;
    for(int i = 0; i < n-1; i++){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> threat(n+1, 0), min_threat(n+1, 0), visited(n+1, 0);
    dfs(1, 0, threat, min_threat, visited, adj, a);
    for(int i = 1; i <= n; i++){
        cout << threat[i] << (i == n ? "\n" : " ");
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