#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k,n,w;
    cin >> k >> n >> w;

    int cost = w * (w+1) * k / 2;
    int leftover = cost - n;

    if(leftover > 0){
        cout << leftover << '\n';
    }
    else{
        cout << 0 << '\n';
    }

    return 0;
}