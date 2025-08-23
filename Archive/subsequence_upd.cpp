#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, l, r; cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<int> first;
        for(int i = 0; i < r; i++){
            first.push_back(a[i]);
        }
        sort(first.begin(), first.end());
        ll ftotal = 0;
        for(int i = 0; i < r - l + 1; i++){
            ftotal += first[i];
        }
        vector<int> second;
        for(int i = l-1; i < n; i++){
            second.push_back(a[i]);
        }
        sort(second.begin(), second.end());
        ll stotal = 0;
        for(int i = 0; i < r - l + 1; i++){
            stotal += second[i];
        }
        cout << min(ftotal, stotal) << '\n';
    }
        

    return 0;
}