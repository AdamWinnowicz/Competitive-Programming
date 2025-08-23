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
    map<int,int> cnt;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        while(a > 0 && a % 2 == 0){
            a/=2; cnt[2]++;
        }
        for(int j = 3; j <= sqrt(a); j+=2){
            while(a > 0 && a % j == 0){
                a /= j; cnt[j]++;
            }
        }
        if(a > 1){
            cnt[a]++;
        }
    }
    int ans = 0, extra = 0;
    for(const auto&p : cnt){
        ans += (p.second / 2);
        if(p.second % 2 == 1){
            extra++;
        }
    }
    ans += extra / 3;
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