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
    map<int, int> components;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        int x = a % k;
        // choose the representative as the smaller of the two common remainders
        components[min(x, k - x)]++;
    }
    for(int i = 0; i < n; i++){
        int b; cin >> b;
        int x = b % k;
        components[min(x, k - x)]--;
    }
    for(auto& c : components){
        if(c.second != 0) return false;
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