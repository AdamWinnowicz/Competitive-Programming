#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, c, q; cin >> n >> c >> q;
    string s; cin >> s;

    vector<ll> segment_diffs, curr_ends;
    ll curr_end = n-1;
    segment_diffs.push_back(0); curr_ends.push_back(curr_end);
    for(int i = 0; i < c; i++){
        ll l, r; cin >> l >> r;
        segment_diffs.push_back(curr_end + 2 - l);
        curr_end += (r - l + 1);
        curr_ends.push_back(curr_end);
    }
    for(int i = 0; i < q; i++){
        ll k; cin >> k; k--;
        while(k >= n){
            ll ind = 0;
            while(curr_ends[ind] < k) ind++;
            k -= segment_diffs[ind];
            //debug(k, ind);
        }
        cout << s[k] << '\n';
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