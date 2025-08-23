#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n);
    for(int i = n-1; i > -1; i--){
        cin >> a[i];
    }
    for(int i = n-1; i > -1; i--){
        cin >> b[i];
    }
    ll ans = 1e18, currsum = 0;
    for(int i = 0; i < n; i++){
        if(n - i <= m){
            ans = min(currsum + a[i], ans);
        }
        currsum += min(a[i], b[i]);
    }
    cout << ans << '\n';
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