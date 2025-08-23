#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m,k; cin >> n >> m >> k;
        int spots;
        if(k%n == 0) spots = k / n;
        else spots = k / n + 1;
        int splits = m - spots;
        int section_length = m / (splits+1);
        cout << section_length << '\n';
    }

    return 0;
}