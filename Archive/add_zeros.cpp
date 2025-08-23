#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(ll currsum, ll& ans, map<ll, vector<ll>>& indices, ll n, set<ll>& visited){
    ans = max(ans, n + currsum);
    if(visited.find(currsum) == visited.end()){
        visited.insert(currsum);
        for(ll ind : indices[currsum]){
            dfs(currsum + ind, ans, indices, n, visited);
        }
    }
}

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    map<ll, vector<ll>> indices;
    for(int i = 0; i < n; i++){
        ll val; cin >> val; a[i] = val - (n - i);
        indices[a[i]].push_back(i);
    }
    ll ans = n;
    set<ll> visited;
    dfs(0, ans, indices, n, visited);
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