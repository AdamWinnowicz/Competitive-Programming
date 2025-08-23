#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    ll m = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m += a[i];
        mx = max(mx, a[i]);
    }
    for(ll s = n; s > 0; s--){
        ll z = m + k;
        ll rem = z % s;
        z -= rem;
        if(z >= m && (z / s) >= mx){
            cout << s << '\n';
            break;
        }
    }

}

int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
}
