#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int n, m; cin >> n >> m;
    cout << "? " << 1 << " " << 1 << '\n'; cout.flush();
    int d; cin >> d;
    int c_dist, r_dist;
    if(d + 1 > n){
        cout << "? " << 1 << " " << d + 1 << '\n'; cout.flush();
        cin >> r_dist;
        cout << "! " << r_dist + 1 << " " << d + 1 << '\n'; cout.flush(); return;
    }
    if(d + 1 > m){
        cout << "? " << d + 1 << " " << 1 << '\n'; cout.flush();
        cin >> c_dist;
        cout << "! " << d + 1 << " " << c_dist + 1 << '\n'; cout.flush(); return;
    }
    cout << "? " << 1 << " " << d + 1 << '\n'; cout.flush();
    cin >> r_dist;
    cout << "? " << d + 1 << " " << 1 << '\n'; cout.flush();
    cin >> c_dist;
    if(c_dist == r_dist){
        cout << "! " << d + 1 << " " << d + 1 << '\n';
    }
    else if(c_dist < r_dist){
        cout << "! " << d + 1 << " " << c_dist + 1 << '\n';
    }
    else{
        cout << "! " << r_dist + 1 << " " << d + 1 << '\n';
    }
    cout.flush();
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