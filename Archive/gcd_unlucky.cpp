#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
bool test_case(){
    int n; cin >> n;
    vector<ll> p(n), s(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n-1; i++){
        if(p[i+1] > p[i]) return false;
    }
    for(int i = 0; i < n-1; i++){
        if(s[i+1] < s[i]) return false;
    }
    if(p[n-1] != s[0]) return false;
    ll g = p[n-1];
    for(int i = 0; i < n-1; i++){
        if(__gcd(p[i], s[i+1]) != g) return false;
    }
    for(int i = 0; i < n-1; i++){
        if(p[i] % p[i+1] != 0) return false;
    }
    for(int i = 0; i < n-1; i++){
        if(s[i+1] % s[i] != 0) return false;
    }
    return true;
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
