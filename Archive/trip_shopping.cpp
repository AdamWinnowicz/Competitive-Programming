#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
void test_case(){
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n);
    vector<pair<int,int>> c;
    ll ans = 1e18 + 10;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c.emplace_back(a[i], i);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        c.emplace_back(b[i], i);
        sum += abs(a[i] - b[i]);
    }
    sort(c.begin(), c.end());
    for(int i = 0; i < 2 * n - 1; i++){
        if(c[i].second != c[i+1].second){
            int bi = c[i].second, bj = c[i+1].second;
            ll curr_diff = abs(a[bi] - b[bi]) + abs(a[bj] - b[bj]);
            vector<int> x = {a[bi], b[bi], a[bj], b[bj]};
            sort(x.begin(), x.end());
            ll new_diff = abs(x[3] - x[0]) + abs(x[2] - x[1]);
            ans = min(ans, sum + (new_diff - curr_diff));
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