#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, l, r; cin >> n >> l >> r;
    vector<int> left(n + 1), right(n + 1);
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        if(i < l){
            left[v]++;
        }
        else right[v]++;
    }
    int left_sum = 0, right_sum = 0;
    for(int x = 1; x <= n; x++){
        int same = min(left[x], right[x]);
        left[x] -= same; right[x] -= same;
        left_sum += left[x], right_sum += right[x];
    }
    int ans = 0;
    for(int x = 1; x <= n; x++){
        if(left_sum > right_sum){
            while(left[x] > 1 && left_sum > right_sum){
                left[x] -= 2;
                left_sum -= 2;
                ans++;
            }
        }
        else{
            while(right[x] > 1 && left_sum < right_sum){
                right[x] -= 2;
                right_sum -= 2;
                ans++;
            }
        }
    }
    ans += max(left_sum, right_sum);
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