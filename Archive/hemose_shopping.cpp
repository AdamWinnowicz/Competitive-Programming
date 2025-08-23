#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n, x; cin >> n >> x;
    vector<ll> a(n), b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    if(x > n - 1){
        for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
        return true;
    }
    for(int i = n - x; i < x; i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}