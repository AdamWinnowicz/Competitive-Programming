#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        multiset<int> not_used;
        for(int i = 0; i < n; i++) {
            cin >> a[i]; 
            not_used.insert(a[i]);
        }
        cout << *max_element(a.begin(),a.end());
        long long prefsum = 0;
        for(int i = n-1; i > -1; i--){
            prefsum += a[i];
            not_used.erase(not_used.find(a[i]));
            if(!not_used.empty()){
                cout << " " << *not_used.rbegin() + prefsum;
            }        
        }
        cout << '\n';
    }
    
    return 0;
}