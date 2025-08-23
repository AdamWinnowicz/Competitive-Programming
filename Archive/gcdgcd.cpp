#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll total_gcd(multiset<ll> multiples){
    ll res = *multiples.begin();
    for(ll val : multiples){
        res = gcd(res, val);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        long long mn = pow(10, 18) + 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        multiset<ll> multiples;
        for(int i = 0; i < n; i++){
            if(a[i] % mn == 0){
                multiples.insert(a[i]);
            }
        }
        multiples.erase(multiples.find(mn));
        if(total_gcd(multiples) == mn){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}