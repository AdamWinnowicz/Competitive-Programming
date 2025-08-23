#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a,b,x,y;
    cin >> a >> b >> x >> y;

    // either bring from a to one of the teleporters and use it
    // or just go in the straight line
    int through1 = abs(a-x) + abs(y-b);
    int through2 = abs(a-y) + abs(x-b);
    int regular = abs(b - a);
    int best = min({through1, through2, regular});
    cout << best;

    return 0;
}