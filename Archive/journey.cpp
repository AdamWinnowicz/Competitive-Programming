#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    ll total = a + b + c;
    ll q = n / total;
    ll r = n % total;
    ll ans = 3 * q;
    if(r > 0){
        r-=a; ans++;
    }
    if(r > 0){
        r-=b; ans++;
    }
    if(r > 0) ans++;
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