#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int total = (x2-x1) * (y2-y1);
    int width = 0, height = 0;
    // first case: the feed board covers the width of the lawnmower board
    if(x3 <= x1 && x1 <= x4 && x3 <= x2 && x2 <= x4 && (y3 <= y1 && y1 <= y4 || y3 <= y2 && y2 <= y4)){
        width = x2 - x1;
        height = max(min(y2,y4)-max(y1,y3),0);
    }
    // second case: the feed board covers the height of the lawnmover board
    if(y3 <= y1 && y1 <= y4 && y3 <= y2 && y2 <= y4 && (x3 <= x1 && x1 <= x4 || x3 <= x2 && x2 <= x4)){
        height = y2 - y1;
        width = max(min(x2,x4)-max(x1,x3),0);
    }
    cout << total - width * height << '\n';

    return 0;
}