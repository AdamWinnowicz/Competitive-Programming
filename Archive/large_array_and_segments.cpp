#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll count_bad(vector<ll> a, ll x){
    ll count = 0;
    ll currtotal = 0;
    for(int i = a.size()-1; i > -1; i--){
        currtotal += a[i];
        if(currtotal >= x){
            break;
        }
        count++;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){

        ll n,k,x; cin >> n >> k >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        ll total = accumulate(a.begin(), a.end(), 0LL);
        ll ans = n * k;
        if(total >= x){
            ans -= count_bad(a, x);
        }
        else{
            ll reps = x / total;
            ll rem = x % total;
            if(reps > k){
                ans = 0;
            }
            else if (reps == k){
                if(rem == 0){
                    ans = 1;
                }
                else{
                    ans = 0;
                }
            }
            else{
                if(rem == 0){
                    ans -= (n * reps - 1);
                }
                else{
                    ans -= n * reps;
                    ans -= count_bad(a, rem);
                }

            }
        }
        cout << ans << '\n';
    }

    return 0;
}