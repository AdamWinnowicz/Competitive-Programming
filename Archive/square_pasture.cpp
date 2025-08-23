#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int a,b,c,d,e,f,g,h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h;
    int left = min(a,e);
    int right = max(c,g);
    int bottom = min(b,f);
    int top = max(d,h);
    int side = max((top-bottom),(right - left));

    cout << side * side << '\n';

    return 0;
}