#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

pair<ll,ll> intersect(ll l1, ll r1, ll l2, ll r2){
    return {max(l1, l2), min(r1, r2)};
}

void test_case(){
    ll n; cin >> n;
    vector<pair<ll,ll>> seg;
    for(int i = 0; i < n; i++){
        ll l, r; cin >> l >> r;
        seg.emplace_back(l, r);
    }
    ll L = 0, R = 1e9;
    while(L < R){
        ll k = L + (R - L) / 2;
        ll bottom = 0, top = 0;
        bool possible = true;
        for(int i = 0; i < n; i++){
            bottom = max(0LL, bottom - k); top = min(top + k, (ll) 1e9);
            pair<ll,ll> s = seg[i];
            pair<ll,ll> info = intersect(bottom, top, s.first, s.second);
            if(info.second < info.first){
                possible = false; break;
            }
            bottom = info.first; top = info.second;
        }
        if(possible){
            R = k;
        }
        else L = k + 1;
    }
    cout << L << '\n';
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