#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, x, k; cin >> n >> x >> k;
        string s; cin >> s;

        ll sum_to_minus_x = 0;
        ll sum = 0;
        bool found = false;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') sum--;
            else sum++;
            sum_to_minus_x++;
            if(sum == -1 * x){
                found = true; break;
            }
        }
        if(!found || sum_to_minus_x > k){
            cout << 0 << '\n'; continue;
        }
        found = false; sum = 0;
        ll sum_to_zero = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L') sum--;
            else sum++;
            sum_to_zero++;
            if(sum == 0){
                found = true; break;
            }
        }
        if(!found){
            cout << 1 << '\n';
        }
        else{
            ll remaining = k - sum_to_minus_x;
            cout << 1 + remaining / sum_to_zero << '\n';
        }

    }

    return 0;
}