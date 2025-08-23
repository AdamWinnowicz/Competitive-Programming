#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    string new_s; int ind = 0;
    while(s[ind] == '0') ind++;
    for(int i = ind; i < n; i++){
        new_s += s[i];
    }
    s = new_s; n = s.length();
    vector<ll> v(n + 9);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += s[i] - '0';
        v[n - i - 1] = sum;
    }
    string ans;
    for(int i = 0; i < n; i++){
        ll curr_val = v[i];
        int carry = 0;
        while(curr_val > 0){
            curr_val /= 10; carry++;
            ll last_digit = curr_val % 10;
            v[i + carry] += last_digit;
        }
        ans += to_string(v[i] % 10);
    }
    //debug(v);
    if(v[n] > 0) ans += to_string(v[n]);
    reverse(ans.begin(), ans.end());
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