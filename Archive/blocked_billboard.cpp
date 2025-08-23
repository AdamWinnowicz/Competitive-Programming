#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1, y1, x2, y2;
    int area() { return (x2-x1) * (y2-y1); }
};

int intersect(Rect p, Rect q){
    return max(min(p.x2,q.x2) - max(p.x1,q.x1),0) * max(min(p.y2,q.y2) - max(p.y1,q.y1),0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    Rect b1, b2, t;
    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    int total = b1.area() + b2.area();
    cout << total - intersect(b1,t) - intersect(b2,t);

    return 0;
}