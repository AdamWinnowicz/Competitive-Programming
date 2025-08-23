#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0, currlen = 0;
    for(int i = 0; i < n; i++){
        if(currlen == k){
            ans++; currlen = -1;
        }
        if(a[i] == 0) currlen++;
        else currlen = 0;
    }
    if(currlen == k) ans++;
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