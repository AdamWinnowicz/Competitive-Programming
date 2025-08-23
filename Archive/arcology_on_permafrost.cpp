#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n, m, k; cin >> n >> m >> k;
    // m is number of times, k is length of seg
    vector<int> ans;
    int low = 0;
    int high = max(n / (m + 1), k);
    while(ans.size() < n){
        for(int i = low; i < high; i++){
            if(ans.size() < n){
                ans.push_back(i);
            }
            else break;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << (i == n-1 ? '\n' : ' ');
    }
}
 
int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
 
}