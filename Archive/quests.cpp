#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        int best = 0, currtotal = 0, biggestb = 0;
        for(int i = 0; i < n; i++){
            if(i == k){
                break;
            }
            currtotal += a[i];
            biggestb = max(biggestb, b[i]);
            int possible = currtotal + biggestb * (k - i - 1);
            best = max(best, possible);
        }
        cout << best << '\n';
    }

    return 0;
}