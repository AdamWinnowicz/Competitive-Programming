#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, k; cin >> n >> k;
    vector<tuple<ll,ll,ll>> info;
    for(int i = 0; i < n; i++){
        ll a, b, c; cin >> a >> b >> c;
        info.push_back({a, b, c});
    }
    sort(info.begin(), info.end(), [](const tuple<ll,ll,ll>& p1, const tuple<ll,ll,ll>& p2){
        if(get<0>(p1) != get<0>(p2)) return get<0>(p1) < get<0>(p2);
        return get<2>(p1) > get<2>(p2);
    });
    ll mx = k;
    for(int i = 0; i < n; i++){
        tuple<ll,ll,ll> stuff = info[i];
        if(get<1>(stuff) < mx) continue;
        if(mx >= get<0>(stuff)){
            mx = max(mx, get<2>(stuff));
        }
    }
    cout << mx << '\n';
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