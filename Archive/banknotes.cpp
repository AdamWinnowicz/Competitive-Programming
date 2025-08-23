#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif
 
void test_case(){
    ll n, k; cin >> n >> k; k++;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    a.push_back(18);
    ll power = 0;
    ll ans = 0;
    string x;
    for(int i = 0; i < n; i++){
        power = a[i];
        ll temp = power;
        ll potential = 0;
        ll p = 0;
        while(temp < a[i+1]){
            potential += 9 * pow(10LL, p);
            p++;
            temp++;
        }
        if(k > potential){
            k -= potential;
            ans += potential * pow(10LL, power);
        }
        else{
            x = to_string(k);
            if(ans != 0) x += to_string(ans);
            break;
        }
    }
    cout << x << '\n';
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