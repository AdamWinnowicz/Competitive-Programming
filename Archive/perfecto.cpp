#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll total = (n)*(n+1)/2;
        ll sq = sqrt(total);
        if(total == sq * sq){
            cout << -1 << '\n';
        }
        else{
            vector<ll> a;
            for(ll i = 1; i <= n; i++){
                a.push_back(i);
            }
            for(ll i = 0; i < n - 1; i++){
                ll count = (i+1)*(i+2)/2;
                ll s = sqrt(count);
                if(count == s*s){
                    a[i]++;
                    a[i+1]--;
                }
            }
            cout << a[0];
            for(int i = 1; i < n; i++){
                cout << " " << a[i];
            }
            cout << '\n';
        }
        
        
    }

    return 0;
}