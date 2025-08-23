#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll n, m; cin >> n >> m;
    // all numbers from max(0, n - m) to n + m
    ll up = n + m;
    n = max(0LL, n - m);
    m = up - n;
    ll buffer = 0;
    for(int b = 0; b < 60; b++){
        if((1LL << b) & n) buffer += (1LL << b);
        if(!((1LL << b) & n) && (1LL << b) - buffer <= m){
            n |= (1LL << b);
        }
    }
    cout << n << '\n';

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