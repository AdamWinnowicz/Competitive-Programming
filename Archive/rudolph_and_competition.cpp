#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, m, h; cin >> n >> m >> h;
    vector<tuple<ll,ll,ll>> info;
    for(int i = 1; i <= n; i++){
        vector<ll> p(m);
        for(int j = 0; j < m; j++){
            cin >> p[j];
        }
        sort(p.begin(), p.end());
        ll points = 0, penalty = 0, time_left = h, time_used = 0;
        for(int j = 0; j < m; j++){
            if(p[j] <= time_left){
                time_left -= p[j]; time_used += p[j];
                points--; penalty += time_used;
            }
        }
        info.push_back({points, penalty, i});
    }
    sort(info.begin(), info.end());
    for(int i = 0; i < n; i++){
        tuple<ll,ll,ll> stuff = info[i];
        //cout << get<0>(stuff) << " " << get<1>(stuff) << " " << get<2>(stuff) << '\n';
        if(get<2>(stuff) == 1){
            cout << i + 1 << '\n'; return;
        }
    }

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
