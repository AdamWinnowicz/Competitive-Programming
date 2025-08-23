#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> suffmin(n);
    int mn = 1e5 + 5;
    for(int i = n-1; i > -1; i--){
        suffmin[i] = mn;
        mn = min(mn, a[i]);
    }
    int ans = 0, i = 0, mx = 0;
    while(i < n){
        int j = i;
        mx = max(mx, a[i]);
        while(suffmin[j] < mx){
            j++;
            mx = max(mx, a[j]);
        }
        ans++;
        i = j + 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}