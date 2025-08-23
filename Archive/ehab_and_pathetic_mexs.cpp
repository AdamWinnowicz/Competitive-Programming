#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> ans(n-1, -1);
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    int start = 0;
    for(vector<int> info : adj){
        if(info.size() > 2){
            for(int i = 0; i < info.size(); i++){
                ans[info[i]] = i;
            }
            start = info.size(); break;
        }
    }
    for(int i = 0; i < n-1; i++){
        if(ans[i] == -1){
            ans[i] = start;
            start++;
        }
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while(t--){
        test_case();
    }

    return 0;
}