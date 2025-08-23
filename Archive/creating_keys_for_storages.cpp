#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, x; cin >> n >> x;
        ll loc = 0;
        for(int i = 0; i < 31; i++){
            if(!((1LL << i) & x)){
                loc = i; break;
            }
        }
        ll highest_bit = 0;
        for(int i = 0; i < 31; i++){
            if(((1LL << i) & x)){
                highest_bit = i;
            }
        }
        ll val = 0;
        for(int i = 0; i < n; i++){
            if(i == n-1){
                if(val < (1LL << highest_bit)) cout << x;
                else cout << val;
            }
            else{
                if(val < (1LL << loc)){
                    cout << val << " ";
                    if(val < (1LL << loc)-1) val++;
                }
                else{
                    cout << val << " ";
                }         
            }
        }
        cout << '\n';
    }

    return 0;
}