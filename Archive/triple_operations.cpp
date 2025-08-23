#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll log3(ll number){
    ll ans = 0;
    while(number > 0){
        number /= 3;
        ans++;
    }
    return ans;
}

void test_case(){
    ll l, r; cin >> l >> r;
    ll ans = log3(l);
    ll curr = l, curr_cost = ans;
    ll next_power = pow(3, ans);
    while(curr <= r){
        if(next_power > r){
            ans += (r - curr + 1) * curr_cost; break;
        }
        ans += (next_power - curr) * curr_cost;
        curr = next_power;
        next_power *= 3;
        curr_cost++;
    }
    cout << ans << '\n';
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