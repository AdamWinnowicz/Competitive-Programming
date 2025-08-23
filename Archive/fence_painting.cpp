#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int total = (b-a) + (d-c);
    int intersection = max(min(b,d) - max(a,c), 0);
    cout << total - intersection << '\n';
    
    return 0;
}