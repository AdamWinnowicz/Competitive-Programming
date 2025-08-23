#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < k-1; i++){
        next_permutation(a.begin(), a.end());
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << (i < n-1 ? ' ' : '\n');
    }

    return 0;
}