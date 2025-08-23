#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m, k; cin >> n >> m >> k;
    int remaining = max(n, m) - k;
    if(remaining < 0 || remaining > min(n, m)) {
        cout << -1 << '\n'; 
        return;
    }
    string ans;
    if(n > m){
        int zeros = n - k, ones = m;
        for(int i = 0; i < k; i++) ans += "0";
        int ind = k;
        while(ind < n + m){
            if(ones > 0){
                ans += "1";
                ones--;
                ind++;
            }
            if(zeros > 0 && ind < n + m){
                ans += "0";
                zeros--;
                ind++;
            }
        }
    }
    else{
        int zeros = n, ones = m - k;
        for(int i = 0; i < k; i++) ans += "1";
        int ind = k;
        while(ind < n + m){
            if(zeros > 0){
                ans += "0";
                zeros--;
                ind++;
            }
            if(ones > 0 && ind < n + m){
                ans += "1";
                ones--;
                ind++;
            }
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