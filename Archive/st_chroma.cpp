#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector<int> a;
        for(int i = 0; i < x; i++){
            a.push_back(i);
        }
        for(int i = n-1; i >= x; i--){
            a.push_back(i);
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << (i == n-1 ? "\n" : " ");
        }
    }

    return 0;
}