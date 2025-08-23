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
        vector<int> b(n);
        int minus_one_count = 0;
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] == -1){
                minus_one_count++;
            }
        }
        if(minus_one_count == n){
            int mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
            cout << k + mn - mx + 1 << '\n';
            continue;
        }
        set<int> sums;
        for(int i = 0; i < n; i++){
            if(b[i] != -1){
                sums.insert(a[i]+b[i]);
            }
        } 
        if(sums.size() == 1){
            int val = *sums.begin();
            bool possible = true;
            for(int i = 0; i < n; i++){
                if(b[i] == -1){
                    if(!(a[i] <= val && val <= a[i] + k)){
                        possible = false;
                        break;
                    }
                }   
            }
            if(possible){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            cout << 0 << '\n';
        }
    }

    return 0;
}