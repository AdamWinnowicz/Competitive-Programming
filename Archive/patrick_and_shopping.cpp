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

    int a, b, c; cin >> a >> b >> c;
    int ans = a + b + c;
    ans = min(ans, 2 * b + 2 * a);
    ans = min(ans, 2 * a + 2 * c);
    ans = min(ans, 2 * b + 2 * c);
    cout << ans << '\n';

    return 0;
}