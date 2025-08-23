#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll,ll> c;

void test_case(){
    ll t, v; cin >> t >> v;
    if(t == 1){
        c[v]++;
    }
    else{
        bool possible = true;
        ll extra_count = 0;
        for(int b = 0; b < 30; b++){
            if(v & (1LL << b)){
                if(c[b] + extra_count == 0){
                    possible = false; break;
                }
                extra_count = (c[b] + extra_count - 1) / 2;
            }
            else{
                extra_count = (c[b] + extra_count) / 2;
            }
            
        }
        cout << (possible ? "YES\n" : "NO\n");
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
    }

    return 0;
}