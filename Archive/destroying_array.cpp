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

    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> pref(n); pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    multiset<ll> d, sums; d.insert(-1), d.insert(n); 
    sums.insert(pref[n-1]);
    for(int i = 0; i < n; i++){
        ll ind; cin >> ind; ind--;
        ll nl = *d.upper_bound(ind);
        ll ns = *prev(d.lower_bound(ind));
        sums.erase((ns == -1 ? sums.find(pref[nl - 1]) : sums.find(pref[nl - 1] - pref[ns])));
        sums.insert(pref[nl - 1] - pref[ind]);
        if(ind > 0) sums.insert((ns == -1 ? pref[ind - 1] : pref[ind - 1] - pref[ns]));
        d.insert(ind);
        ll mx = *prev(sums.end());
        cout << mx << '\n';
    }

    return 0;
}