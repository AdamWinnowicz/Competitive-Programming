#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int loc = n;
    for(int i = 0; i < n; i++){
        if(a[i] > a[k-1]){
            loc = i; swap(a[i], a[k-1]); break;
        }
    }
    int ans = 0;
    if(loc < k-1){
        if(loc > 0) ans++;
        for(int i = loc+1; i < n; i++){
            if(a[i] < a[loc]){
                ans++;
            }
            else break;
        }
    }
    //cout << ans << " " << loc << '\n';
    cout << max(ans, loc-1) << '\n';


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