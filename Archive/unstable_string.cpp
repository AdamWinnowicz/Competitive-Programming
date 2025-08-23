#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

ll pairs(ll len){
    return len * (len + 1) / 2;
}

void test_case(){
    string s; cin >> s; 
    ll n = s.length();
    vector<ll> prev(n);
    ll curr_count = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '?') curr_count++;
        else curr_count = 0;
        prev[i+1] = curr_count;
    }
    ll ans = 0;
    ll currlen = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == '?') currlen++;
        else if(s[i] == s[i-1]){
            ans += pairs(currlen);
            currlen = 1;
        }
        else if(s[i-1] == '?'){
            if(i - prev[i] - 1 < 0){
                currlen++; continue;
            }
            if(prev[i] % 2 == 1){
                if(s[i] == s[i-prev[i]-1]){
                    currlen++;
                }
                else{
                    ans += pairs(currlen) - pairs(prev[i]);
                    currlen = prev[i] + 1;
                }
            }
            else{
                if(s[i] != s[i-prev[i]-1]){
                    currlen++;
                }
                else{
                    ans += pairs(currlen) - pairs(prev[i]);
                    currlen = prev[i] + 1;
                }
            }
        }
        else{
            currlen++;
        }
    }
    ans += pairs(currlen);
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