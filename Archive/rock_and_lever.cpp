#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // keep track of the number of highest bits that are at each location
    vector<ll> count(33, 0);
    for(int i = 0; i < n; i++){
        for(int b = 32; b > -1; b--){
            if((1LL << b) & a[i]){
                count[b]++;
                break;
            }
        }
    }
    ll ans = 0;
    for(int b = 0; b < 33; b++){
        //cout << b << " " << count[b] * (count[b] - 1) / 2 << '\n';
        ans += count[b] * (count[b] - 1) / 2;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}