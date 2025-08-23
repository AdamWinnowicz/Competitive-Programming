#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        string s; cin >> s;
        int zero_count = 0, one_count = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') zero_count++;
            else one_count++;
        }
        int max_pairs = n / 2;
        if(one_count % 2 == 1) max_pairs = n / 2 - 1;
        int min_pairs = (max(one_count, zero_count) - min(one_count, zero_count)) / 2;
        if(min_pairs <= k && k <= max_pairs && k % 2 == min_pairs % 2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}