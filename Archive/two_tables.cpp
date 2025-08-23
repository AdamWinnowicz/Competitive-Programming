#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int W,H; cin >> W >> H;
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        int w,h; cin >> w >> h;
        if(W - x2 >= w || x1 >= w || H - y2 >= h || y1 >= h){
            cout << 0 << '\n';
            continue;
        }
        int dist = -1;
        if((x2 - x1) + w <= W){
            int curr_space = max(x1, W - x2);
            dist = max(0, w - curr_space);
        }
        if((y2 - y1) + h <= H){
            int curr_space = max(y1, H - y2);
            if(dist == -1){
                dist = max(0, h - curr_space);
            }
            else{
                dist = min(dist, max(0, h - curr_space));
            }
        }
        cout << dist << '\n';
    }

    return 0;
}