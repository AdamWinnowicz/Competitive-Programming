#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int l,r; cin >> l >> r;
    if(r - l >= 1){
        if(r % 2 == 0 && r > 2){
            cout << 2 << " " << r-2 << '\n';
        }
        else if(r-1 > 2){
            cout << 2 << " " << r-3 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    else{
        int factor = -1;
        for(int f = 2; f <= sqrt(l); f++){
            if(l % f == 0){
                factor = f; break;
            }
        }
        if(factor == -1){
            cout << -1 << '\n';
        }
        else{
            cout << factor << " " << l - factor << '\n';
        }
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