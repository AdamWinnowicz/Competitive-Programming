#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void test_case(){
    ll n; cin >> n;
    ll ans = 1;
    while(n > 3){
        n /= 4;
        ans *= 2LL;
    }
    cout << ans << '\n';
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