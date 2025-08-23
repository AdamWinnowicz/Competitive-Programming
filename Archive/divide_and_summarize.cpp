#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> pref(n); pref[0] = a[0];
    for(int i = 1; i < n; i++) pref[i] = pref[i-1] + a[i];
    set<ll> sums;
    vector<pair<int,int>> st = {{0, n-1}};
    while(!st.empty()){
        pair<int,int> c = st.back();
        st.pop_back();
        int l = c.first, r = c.second;
        ll sum = (l == 0 ? pref[r] : pref[r] - pref[l-1]);
        sums.insert(sum);
        if(l == r) continue;
        int x = (a[r] + a[l]) / 2;
        auto it = upper_bound(a.begin(), a.end(), x);
        int middle_idx = it - a.begin();
        if(middle_idx <= r){
            st.push_back({l, middle_idx-1});
            st.push_back({middle_idx, r});
        }
    }
    for(int i = 0; i < q; i++){
        int s; cin >> s;
        if(sums.find(s) != sums.end()){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
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