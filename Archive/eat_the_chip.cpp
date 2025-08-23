#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    int h, w, xa, ya, xb, yb; cin >> h >> w >> ya >> xa >> yb >> xb;
    if(ya >= yb){
        cout << "Draw\n"; return;
    }
    // alice moves first
    // if apart by an even number of moves she can try to win, otherwise she will try to avoid losing
    int dy = yb - ya - 1;
    int dx = abs(xa - xb);
    if(dx == 0){
        cout << (dy % 2 == 0 ? "Alice\n" : "Bob\n"); return;
    }
    int dwall;
    if(dy % 2 == 0){
        if(xa > xb) dwall = xb - 1;
        else dwall = w - xb;
        cout << (dx == 1 || dy / 2 - dwall >= dx - 1? "Alice\n" : "Draw\n");
    }
    else{
        if(xb > xa) dwall = xa - 1;
        else dwall = w - xa;
        cout << (dy / 2 - dwall >= dx - 1? "Bob\n" : "Draw\n");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}