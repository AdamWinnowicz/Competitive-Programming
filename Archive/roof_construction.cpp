#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n; n--;
    int highest_bit = 0;
    for(int b = 32; b > -1; b--){
        if((1LL << b) & n){
            highest_bit = b; break;
        }
    }
    for(int i = 1; i < (1 << highest_bit); i++){
        cout << i << " ";
    }
    cout << 0 << " ";
    if(n == (1 << highest_bit)) {
        cout << (1 << highest_bit) << '\n'; return;
    }
    for(int i = (1 << highest_bit); i <= n; i++){
        cout << i << (i == n ? "\n" : " ");
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