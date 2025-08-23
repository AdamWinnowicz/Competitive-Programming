#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n), t(n);
    map<ll, ll> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++){
        x[a[i]] = max(x[a[i]], t[i]);
    }
    a.clear(); t.clear();
    for(const auto& p : x){
        a.push_back(p.first);
        t.push_back(p.second);
    }
    //find location with maximum a[i] + t[i]
    ll mx = 0, mx_ind = -1;
    for(int i = 0; i < a.size(); i++){
        ll curr = a[i] + t[i];
        if(curr >= mx){
            mx_ind = i;
            mx = curr;
        }
    }
    ll left = t[0], right = mx;
    ll prev = 0;
    for(int i = 0; i <= mx_ind; i++){
        ll prev_left = left, prev_right = right;
        if(i > 0) left = max(t[i], left + (a[i] - prev));
        right -= (a[i] - prev);
        if(left == right){
            cout << a[i] << '\n'; return;
        }
        else if(left > right){
            double location = prev;
            location += ((double) prev_right - prev_left) / 2;
            cout << fixed << setprecision(7) << location << '\n'; return;
        }
        prev = a[i];
    }
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