#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i]; 
        ll ans = 1000000000000;
        ll i = 0;
        while(i < n){
            ll j = i;
            while(j < n-1 && a[j+1] == a[i]){
                j++;
            }
            ans = min(ans, (n - (j - i + 1)) * a[i]);
            i = j + 1;
        }
        cout << ans << '\n';

        
    }

    return 0;
}