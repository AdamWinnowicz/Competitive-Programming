#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int x, n, m; cin >> x >> n >> m;
        if(x == 0){
            cout << "0 0\n"; continue;
        }
        n = min((int) ceil(log2(x)) + 1, n), m = min((int) ceil(log2(x)) + 1, m);
        int tn = n, tm = m;
        int mx = x, mn = x, cnt = 0;
        while(n > 0){
            mx = floor(mx / 2.0); n--;
        }
        while(m > 0){
            mx = ceil(mx / 2.0); m--;
        }
        n = tn; m = tm; cnt = 0;
        while(m > 0){
            mn = ceil(mn / 2.0); m--;
        }
        while(n > 0){
            mn = floor(mn / 2.0); n--;
        }
        cout << mn << " " << mx << '\n';
    }

    return 0;
}