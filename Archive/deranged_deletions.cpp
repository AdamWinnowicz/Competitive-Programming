#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int mx = 0;
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(a[i] < mx){
            cout << "YES\n";
            cout << 2 << '\n';
            cout << mx << " " << a[i] << '\n';
            found = true; break;
        }
        mx = max(mx, a[i]);
    }
    if(!found){
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << test_case() ? "Yes\n" : "No\n";
    }

    return 0;
}