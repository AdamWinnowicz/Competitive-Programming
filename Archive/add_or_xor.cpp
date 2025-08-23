#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int a, b, x, y; cin >> a >> b >> x >> y;
    if(a > b){
        if(a % 2 == 1 && a - 1 == b){
            cout << y << '\n';
        }
        else cout << -1 << '\n';
    }
    else{
        if(x < y){
            cout << (b-a) * x << '\n';
        }
        else{
            int ans = 0;
            while(a < b){
                if(a % 2 == 0){
                    ans += y;
                }
                else{
                    ans += x;
                }
                a++;
            }
            cout << ans << '\n';
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