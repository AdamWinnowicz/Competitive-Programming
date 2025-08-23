#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int mx = 0;
    int curr = 0;

    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        curr -= a;
        curr += b;
        if(curr > mx) mx = curr;
    }

    cout << mx << '\n';

    return 0;
}