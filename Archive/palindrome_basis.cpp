#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

bool is_palindrome(ll n){
    string s = to_string(n);
    int l = 0, r = s.length()-1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

vector<ll> dp(40005, 0LL);

void test_case(){
    ll n; cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dp[0] = 1;
    for(ll i = 1; i < 40005; i++){
        if(is_palindrome(i)){
            for(ll j = i; j < 40005; j++){
                dp[j] = (dp[j] + dp[j-i]) % MOD;
            }
        }
    }


    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}