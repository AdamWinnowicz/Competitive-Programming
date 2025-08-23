#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

bool test_case(){
    int n, k; cin >> n >> k;
    if(n == k) return true;
    if(k == 3){
        return n % 4 != 0;
    }
    if(k % 3 == 0){
        n %= (k + 1);
        return n == k || n % 3 != 0;
    }
    if(n % 3 == 0){
        return false;
    }
    else{
        return true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Alice\n" : "Bob\n");
    }

    return 0;
}