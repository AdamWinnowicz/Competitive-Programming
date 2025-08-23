#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
    }
    vector<ll> b = a;
    while(b.size() > 1){
        ll sum = 0;
        vector<ll> replace;
        for(int i = 1; i < b.size(); i++){
            replace.push_back(b[i] - b[i-1]);
            sum += b[i] - b[i-1];
        }
        if(sum < 0){
            sum *= -1;
            for(int i = 0; i < replace.size(); i++){
                replace[i] *= -1;
            }
        }
        ans = max(ans, sum);
        b = replace;
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