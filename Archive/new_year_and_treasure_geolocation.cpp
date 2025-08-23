#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll distance(pair<ll,ll> c1, pair<ll,ll> c2){
    ll dx = (c1.first - c2.first), dy = (c1.second - c2.second);
    ll d2 = dx * dx + dy * dy;
    return d2;
}

void test_case(){
    int n; cin >> n;
    vector<pair<ll,ll>> locs, clues;
    ll sum_x = 0, sum_y = 0, sum_a = 0, sum_b = 0;
    for(int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;
        sum_x += x; sum_y += y;
    }
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        sum_a += a; sum_b += b;
    }
    ll tx = (sum_x + sum_a) / n;
    ll ty = (sum_y + sum_b) / n;
    cout << tx << " " << ty << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}