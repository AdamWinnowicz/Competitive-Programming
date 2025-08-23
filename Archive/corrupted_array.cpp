#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<ll> b(n+2);
    ll sum = 0;
    for(int i = 0; i < n+2; i++){
        cin >> b[i]; sum += b[i];
    }
    sort(b.begin(), b.end());
    if(b[n] == sum - b[n] - b[n+1]){
        for(int i = 0; i < n; i++){
            cout << b[i] << (i == n-1 ? "\n" : " ");
        }
        return;
    }
    vector<int> ans;
    bool found = false;
    for(int x = 0; x < n+1; x++){
        if(b[n+1] == sum - b[n+1] - b[x]){
            for(int i = 0; i < n+1; i++){
                if(i != x) ans.push_back(b[i]);
            }
            found = true; break;
        }
    }
    if(found){
        for(int i = 0; i < n; i++){
            cout << ans[i] << (i == n-1 ? "\n" : " ");
        }
    }
    else cout << -1 << '\n';

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