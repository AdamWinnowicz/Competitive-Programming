#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    for(int i = 0; i < n; i++) cin >> y[i];
    vector<ll> d(n);
    for(int i = 0; i < n; i++){
        d[i] = x[i] - y[i];
    }
    sort(d.begin(), d.end());
    int l = 0, r = n-1;
    int ans = 0;
    while(l < r){
        if(d[l] + d[r] <= 0){
            ans++;
            l++; r--;
        }
        else r--;
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