#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; long long k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> costs;
        for(int i = 0; i < n; i++){
            for(int bit = 0; bit < 60; bit++){
                long long val = (1LL << bit);
                if(val & a[i]){
                    ans++;
                }
                else{
                    costs.push(val);
                }
            }
        }
        while(!costs.empty()){
            if(k >= costs.top()){
                k -= costs.top();
                ans++;
                costs.pop();
            }
            else{
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}