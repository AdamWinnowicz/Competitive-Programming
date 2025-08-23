#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            ll max_weight = 0, min_weight = 1e15;
            for(int j = 0; j < n; j+=i){
                ll weight = 0;
                for(int k = j; k < j+i; k++){
                    weight += a[k];
                }
                max_weight = max(max_weight, weight);
                min_weight = min(min_weight, weight);
            }
            ans = max(ans, max_weight - min_weight);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case ? "Yes\n" : "No\n");
    }

    return 0;
}