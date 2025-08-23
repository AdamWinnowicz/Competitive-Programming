#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 1;
    vector<ll> diffs;
    for(int i = 1; i < n; i++){
        ll diff = a[i] - a[i-1];
        if(diff > x){
            diffs.push_back(diff);
            ans++;
        }
    }
    sort(diffs.begin(), diffs.end());
    for(int i = 0; i < diffs.size(); i++){
        ll moves = (diffs[i]-1) / x;
        if(k >= moves){
            k -= moves;
            ans--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    test_case();

    return 0;
}