#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    ll n, k; cin >> n >> k;
    vector<int> h(n), p(n);
    int max_health = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i]; max_health = max(max_health, h[i]);
    }
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        a[i] = {p[i], h[i]};
    }
    sort(a.begin(), a.end());
    ll total_damage = k;
    for(int i = 0; i < n; i++){
        while(a[i].second > total_damage){
            k = max(0LL, k - a[i].first);
            total_damage += k;
            if(k == 0) break;
        }
        if(k == 0) break;
    }
    return total_damage >= max_health;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}