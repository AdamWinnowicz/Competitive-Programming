#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        int mx = *max_element(a.begin(),a.end()), mn = *min_element(a.begin(),a.end());
        if(mx - mn > k + 1 || (mx - mn == k + 1 && count(a.begin(),a.end(),mx) > 1)){
            cout << "Jerry\n";
        }
        else{
            long long total = accumulate(a.begin(),a.end(),0LL);
            if(total % 2 == 1){
                cout << "Tom\n";
            }
            else{
                cout << "Jerry\n";
            }
        }
    }
 
    return 0;
}