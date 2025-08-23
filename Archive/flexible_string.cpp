#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    set<char> chrs;
    vector<char> cs;
    for(auto& c : a){
        chrs.insert(c);
    }
    for(const auto& c : chrs){
        cs.push_back(c);
    }
    if(chrs.size() <= k){
        cout << n * (n + 1) / 2 << '\n'; return;
    }
    ll ans = 0;
    int m = cs.size();
    for(int mask = 0; mask < (1 << m); mask++){
        if(__builtin_popcount(mask) == k){
            bitset<26> used;
            for(int i = 0; i < m; i++){
                if(mask & (1 << i)) used[cs[i] - 'a'] = 1;
            }
            ll count = 0;
            ll currlen = 0;
            for(int i = 0; i < n; i++){
                if(used[a[i] - 'a'] || a[i] == b[i]) currlen++;
                else{
                    count += currlen * (currlen + 1) / 2;
                    currlen = 0;
                }
            }
            count += currlen * (currlen + 1) / 2;
            ans = max(count, ans);
        }
    }
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