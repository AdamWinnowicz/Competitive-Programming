#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll a, b, c, d; cin >> a >> b >> c >> d;
    for(ll x = a + 1; x <= c; x++){
        ll multiple = (a * b) / __gcd(a * b, x);
        //cout << multiple << '\n';
        ll low = (b+1) / multiple, high = d / multiple;
        if(high > low){
            cout << x << " " << (low + 1) * multiple << '\n'; return;
        }
        else{
            if((b + 1) % multiple == 0){
                cout << x << " " << low * multiple << '\n'; return;
            }
            if(d % multiple == 0){
                cout << x << " " << high * multiple << '\n'; return;
            }
        }
    }
    cout << -1 << " " << -1 << '\n';

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