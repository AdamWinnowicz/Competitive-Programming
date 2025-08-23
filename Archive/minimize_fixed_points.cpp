#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n; cin >> n;
    vector<ll> ans(n + 1);
    iota(ans.begin(), ans.end(), 0);
    vector<ll> prime(n + 1, 1);
    prime[0] = prime[1] = 0;
    for(ll i = 2; i <= n; i++){
        if(prime[i]){
            for(ll j = i * i; j <= n; j += i){
                prime[j] = 0;
            }
        }
    }
    vector<ll> primes;
    for(ll i = 2; i <= n; i++) if(prime[i]) primes.push_back(i);
    vector<bool> used(n + 1, 0);
    for(int i = primes.size() - 1; i > -1; i--){
        ll p = primes[i];
        vector<ll> x;
        vector<ll> open_coords;
        for(ll j = p; j <= n; j += p){
            if(!used[j]){
                x.push_back(j);
                used[j] = true;
                open_coords.push_back(j);
            }
        }
        int pointer = 0;
        ll m = x.size();
        ans[open_coords[pointer]] = x[m - 1]; 
        pointer++;
        for(int j = 0; j < m - 1; j++){
            ans[open_coords[pointer]] = x[j];
            pointer++;
        }
        
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << (i == n ? "\n" : " ");
    }
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