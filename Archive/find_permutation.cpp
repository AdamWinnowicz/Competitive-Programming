#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 1; i <= n; i++){
            string s; cin >> s;
            int onleft = 0;
            for(int j = 0; j < i-1; j++){
                if(s[j] == '1') onleft++;
            }
            for(int j = i; j < n; j++){
                if(s[j] == '0') onleft++;
            }
            a[onleft] = i;
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << (i == n-1 ? '\n' : ' ');
        }

        
    }

    return 0;
}