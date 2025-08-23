#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> dp(n+1, 0);
    for(int i = 0; i < n; i++){
        if(i < m){
            dp[i] = a[i];
        }
        else{
            dp[i] = a[i] + dp[i-m];
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += dp[i];
        cout << sum << (i == n-1 ? "\n" : " ");
    }

    return 0;
}