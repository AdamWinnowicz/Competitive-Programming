#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    ll count = 0;
    for(int i = 0; i < n; i++){
        ll a; cin >> a;
        while(a % 2 == 0){
            a /= 2; count++;
        }
    }
    if(count >= n){
        cout << 0 << '\n'; return;
    }
    vector<ll> pows;
    for(int i = 1; i <= n; i++){
        ll ind = i;
        ll p = 0;
        while(ind % 2 == 0){
            ind /= 2; p++;
        }
        pows.push_back(p);
    }
    sort(pows.begin(), pows.end(), greater<int>());
    ll ops = 0;
    for(int i = 0; i < pows.size(); i++){
        count += pows[i]; ops++;
        if(count >= n){
            cout << ops << '\n'; return;
        }
    }
    cout << -1 << '\n';
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