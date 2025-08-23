#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        ans[a[i]-1] = i+1;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? "\n" : " ");
    }

    return 0;
}