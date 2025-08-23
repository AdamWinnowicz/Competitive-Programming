#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    ll a, k; cin >> a >> k;
    ll prev = -1;
    ll i = 1;
    while(i < k && a != prev){
        int mindigit = 10, maxdigit = -1;
        ll val = a;
        while(val > 0){
            int digit = val % 10;
            val /= 10;
            mindigit = min(mindigit, digit);
            maxdigit = max(maxdigit, digit);
        }
        prev = a;
        //cout << a << " " << maxdigit << " " << mindigit << '\n';
        a += mindigit * maxdigit;
        i++;
    }
    cout << a << '\n';
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