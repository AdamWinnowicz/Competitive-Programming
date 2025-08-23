#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0; int x = 0;
    ll distinct = (k + m - 1) / m;
    for(int i = 0; i < distinct; i++){
        if(i == distinct - 1){
            ans += k * (a[i] + x);
        }
        else{
            ans += m * (a[i] + x);
            x += m; k -= m;
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