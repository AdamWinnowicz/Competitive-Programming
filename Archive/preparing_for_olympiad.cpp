#include <bits/stdc++.h>
using namespace std;

void test_case(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i] > b[i+1]) ans += a[i]-b[i+1];
    }
    cout << ans + a[n-1] << '\n';
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