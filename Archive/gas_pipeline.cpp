#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    ll ans = n * a + (n+1) * b;

    vector<pair<ll,ll>> segments;
    ll l = -1, r = -1;
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            if(s[i-1] == '1') r++;
            else l = r = i;
        }
        else if(s[i-1] == '1'){
            segments.push_back({l,r});
            ans += (r - l + 2) * b;
        }
    }

    if(segments.size() > 0){
        ans += 2*a;
        for(int i = 0; i < segments.size()-1; i++){
            ll d = segments[i+1].first - segments[i].second;
            ans += min(2 * a, (d-2) * b);
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