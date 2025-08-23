#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n % 2 == 0){
            cout << -1 << '\n';
        }
        else{
            vector<int> a(n);
            for(int i = 0; i < n; i+= 2){
                a[i] = i / 2 + 1;
            }
            for(int i = 1; i < n; i+= 2){
                a[i] = a[n-1] + i / 2 + 1;
            }
            for(int i = 0; i < n; i++){
                cout << a[i] << (i == n-1 ? "\n" : " ");
            }
        }
    }

    return 0;
}