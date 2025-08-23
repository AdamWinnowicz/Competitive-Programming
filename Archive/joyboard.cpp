#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, m, k; cin >> n >> m >> k;
    if(k == 1){
        cout << 1 << '\n';
    }
    else if(k == 2){
        if(m >= n) cout << m / n + n - 1 << '\n';
        else cout << m << '\n';
    }
    else if(k == 3){
        if(m >= n) cout << m - n - (m - n) / n << '\n';
        else cout << 0 << '\n';
    }
    else cout << 0 << '\n';
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