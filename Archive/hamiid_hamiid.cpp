#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, x; cin >> n >> x; x--;
    string s; cin >> s;
    int l = x - 1, r = x + 1;
    while(l > -1){
        if(s[l] == '#'){
            break;
        }
        l--;
    }
    while(r < n){
        if(s[r] == '#'){
            break;
        }
        r++;
    }
    int ans = min(n - x, x + 1);
    int either_one = max(l + 2, n - r + 1);
    either_one = max(either_one, 1);
    ans = min(ans, either_one);
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