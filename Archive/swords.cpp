#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>()); 
    int mx = a[0];
    int ind = 0;
    while(a[ind] == mx) ind++;
    int g = mx - a[ind];
    ll sum = mx - a[ind];
    for(int i = ind + 1; i < n; i++){
        g = __gcd(g, mx - a[i]);
        sum += (mx - a[i]);
    }
    cout << sum / g << " " << g << '\n';

    return 0;
}