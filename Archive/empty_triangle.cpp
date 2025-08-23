#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n; cin >> n;
    mt19937 generator(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> distribution(1, 3);
    int a = 1, b = 2, c = 3;
    int curr;
    while(true){
        cout << "? " << a << " " << b << " " << c << '\n'; cout.flush();
        cin >> curr;
        if(curr == -1) return;
        if(curr == 0){
            cout << "! " << a << " " << b << " " << c << '\n'; cout.flush();
            return;
        }
        int r = distribution(generator);
        if(r == 1) a = curr;
        if(r == 2) b = curr;
        if(r == 3) c = curr;
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