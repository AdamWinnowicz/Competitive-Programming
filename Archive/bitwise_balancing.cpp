#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    ll b, c, d; cin >> b >> c >> d;
    ll a = 0;
    for(int x = 0; x <= 62; x++){
        bool b_bit = b & (1LL << x), c_bit = c & (1LL << x);
        if(d & (1LL << x)){
            if(!b_bit && c_bit){
                cout << "-1\n"; return;
            }
            if(!b_bit && !c_bit){
                a += (1LL << x);
            }
        }
        else{
            if(b_bit && !c_bit){
                cout << "-1\n"; return;
            }
            if(c_bit){
                a += (1LL << x);
            }
        }
    }
    cout << a << '\n';
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