#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll n, x; cin >> n >> x;
    ll bw = n - x, fw = n + (x - 2);
    set<ll> k;
    for(ll f = 1; f <= sqrt(bw); f++){
        if(bw % f == 0){
            if(f / 2 + 1 >= x && f % 2 == 0) k.insert(f / 2 + 1);
            ll comp = bw / f;
            if(comp / 2 + 1 >= x && comp % 2 == 0) k.insert(comp / 2 + 1);
        }
    }
    for(ll f = 1; f <= sqrt(fw); f++){
        if(fw % f == 0){
            if(f / 2 + 1 >= x && f % 2 == 0) k.insert(f / 2 + 1);
            ll comp = fw / f;
            if(comp / 2 + 1 >= x && comp % 2 == 0) k.insert(comp / 2 + 1);
        }
    }
    cout << k.size() << '\n';
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