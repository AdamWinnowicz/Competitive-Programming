#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int x, y, k; cin >> x >> y >> k;
    int q = x / y, r = x % y;
    while(k >= (y - r)){
        if(x == 1){
            k %= (y-1);
            break;
        }
        k -= (y - r);
        x = q + 1;
        while(x % y == 0){
            x /= y;
        }
        q = x / y;
        r = x % y;
    }
    if(k > 0){
        x += k;
    }
    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        test_case();
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}