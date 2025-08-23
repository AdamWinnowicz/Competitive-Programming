#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> adj[n+1];

    for(int i = 0; i < n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> sinks;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() == 0){
            sinks.push_back(i);
        }
    }
    if(sinks.size() == 1){
        cout << sinks[0] << '\n';
    }
    else{
        cout << -1 << '\n';
    }
    return 0;
}