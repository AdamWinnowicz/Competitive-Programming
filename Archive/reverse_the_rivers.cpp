#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, q; cin >> n >> k >> q;
    vector<vector<ll>> g(k, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> g[j][i];
        }
    }
    for(int i = 0; i < k; i++){
        vector<ll> v = g[i];
        ll OR = v[0];
        for(int j = 1; j < n; j++){
            OR |= v[j];
            v[j] = OR;
        }
        g[i] = v;
    }
    for(int i = 0; i < q; i++){
        ll m; cin >> m;
        ll l = 0, r = n - 1;
        for(int j = 0; j < m; j++){
            ll R, c; char o; cin >> R >> o >> c; R--;
            vector<ll>& row = g[R];
            if(o == '>'){
                auto it = upper_bound(row.begin(), row.end(), c);
                ll ind = it - row.begin();
                l = max(l, ind);
            }
            else{
                auto it = lower_bound(row.begin(), row.end(), c);
                if(it == row.begin()){
                    r = -1;
                }
                it--;
                ll ind = it - row.begin();
                r = min(r, ind);
            }
        }
        if(l <= r){
            cout << l + 1 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}