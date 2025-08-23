#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int w,h,a,b; cin >> w >> h >> a >> b;
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

        if((abs(y1-y2) % b == 0 && abs(y1-y2) > 0) || (abs(x1-x2) % a == 0 && abs(x1-x2) > 0)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }

    return 0;
}