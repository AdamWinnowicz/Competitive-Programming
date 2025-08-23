#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> a(n), count(100005, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        count[a[i]]++;
    }
    vector<ll> dp(100005, 0);
    dp[1] = count[1];
    for(int i = 2; i < 100005; i++){
        dp[i] = max(dp[i-1], dp[i-2] + count[i] * i);
    }
    cout << dp[100004] << '\n';


    return 0;
}