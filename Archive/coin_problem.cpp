#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> coins = {1, 3, 6, 10, 15};
vector<int> dp(30, 1e9+1);

void test_case(){
    int n; cin >> n;
    int rem = n%15;
    ll ans = -1;
    if(n >= 30){
        ans = n / 15 + min(dp[rem], dp[rem+15] - 1);
    }
    else ans = dp[n];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int coin : coins){
        dp[coin] = 1;
        for(int i = coin; i < 30; i++){
            dp[i] = min(dp[i], dp[i-coin] + 1);
        }
    }


    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}