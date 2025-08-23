#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(),a.end());
        int even = 0, odd = 0;
        vector<int> evens; vector<int> odds;
        for(int i = 0; i < n-1; i++){
            if(a[i] % 2 == 0){
                even++;
                evens.push_back(i);
            }
            else{
                odd++;
                odds.push_back(i);
            }
        }
        if(a[n-1] % 2 == 0 && odd != 0){
            for(int ind : odds){
                a[n-1] += a[ind] -1;
                a[ind] = 1;
            }
            for(int ind : evens){
                a[n-1] += a[ind];
                a[ind] = 0;
            }
        }
        if(a[n-1] % 2 == 1 && even != 0){
            for(int ind : evens){
                a[n-1] += a[ind];
                a[ind] = 0;
            }
            for(int ind : odds){
                a[n-1] += a[ind] - 1;
                a[ind] = 1;
            }
        }
        if(a[n-1] % 2 == 0 && find(a.begin(),a.end(),1) != a.end()) a[n-1]++;
        cout << a[n-1] << '\n';

        
    }
    return 0;
}