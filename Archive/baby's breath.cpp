#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int power[100001];
    power[0] = 1;
    for(int i = 1; i < 100001; i++){
        power[i] = 2 * power[i-1] % MOD;
    }

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n), q(n);
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> q[i];
        vector<int> r(n);
        int tml = -1, tm = -1, bml = -1, bm = -1;
        for(int i = 0; i < n; i++){
            if(p[i] > tm){
                tm = p[i];
                tml = i;
            }
            if(q[i] > bm){
                bm = q[i];
                bml = i;
            }
            int best_top = -1, best_bottom = -1;
            int complement1 = q[i- tml];
            int complement2 = p[i - bml];
            if(tm == bm){
                if(complement1 >= complement2){
                    best_top = tm;
                    best_bottom = complement1;
                }
                else{
                    best_top = complement2;
                    best_bottom = bm;
                }
            }
            else{
                if(tm > bm){
                    best_top = tm;
                    best_bottom = complement1;
                }
                else{
                    best_top = complement2;
                    best_bottom = bm;
                }
            }
            r[i] = (power[best_top] + power[best_bottom]) % MOD;
        }
        for(int i = 0; i < n; i++){
            cout << r[i] << (i == n-1 ? "\n" : " ");
        }
    }

    return 0;
}