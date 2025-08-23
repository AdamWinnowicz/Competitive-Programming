#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, s; cin >> n >> s;
        vector<pair<int,int>> corners;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int dx,dy,x,y; cin >> dx >> dy >> x >> y;
            if(dx == 1 && dy == 1 && y == x){
                ans++;
            }
            if(dx == 1 && dy == -1 && abs(s-x) == y){
                ans++;
            }
            if(dx == -1 && dy == 1 && abs(s-y) == x){
                ans++;
            }
            if(dx == -1 && dy == -1 && y == x){
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}