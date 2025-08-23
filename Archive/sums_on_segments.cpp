// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    int ind = n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(abs(a[i]) != 1) ind = i;
    }
    ll x = (ind == n ? -1 : a[ind]);
    set<ll> ans;
    set<ll> last = {a[0]};
    for(int i = 1; i < n; i++){
        if(a[i] == 1LL){
            last.insert(*prev(last.end()) + 1);
            ans.insert(*last.begin());
            last.erase(*last.begin());
            if(ind != -1 && i < ind) last.insert(a[i]);
        }
        else if(a[i] == -1LL){
            last.insert(*last.begin() - 1);
            ans.insert(*prev(last.end()));
            last.erase(*prev(last.end()));
            if(ind != -1 && i < ind) last.insert(a[i]);
        }
        else{
            ll least = -1, greatest = -1;
            if(x > 0){
                least = *last.begin() + x;
            }
            else{
                greatest = *prev(last.end()) + x;
            }
            set<ll> new_last;
            for(ll val : last){
                if((x > 0 && val < least) || (x < 0 && val > greatest)){
                    ans.insert(val);
                }
                else new_last.insert(val);
                new_last.insert(val + x);
            }
            if(!new_last.empty()){
                last = new_last;
            }
        }
    }
    for(ll val : last){
        ans.insert(val);
    }
    if(ind != n){
        last = {x};
        for(int i = ind + 1; i < n; i++){
            if(a[i] == 1LL){
                last.insert(*prev(last.end()) + 1);
                ans.insert(*last.begin());
                last.erase(*last.begin());
            }
            else{
                last.insert(*last.begin() - 1);
                ans.insert(*prev(last.end()));
                last.erase(*prev(last.end()));
            }
        }
        for(ll val : last){
            ans.insert(val);
        }
        if(ind != n - 1){
            last = {a[ind + 1]};
            for(int i = ind + 2; i < n; i++){
                if(a[i] == 1LL){
                    last.insert(*prev(last.end()) + 1);
                    ans.insert(*last.begin());
                    last.erase(*last.begin());
                    last.insert(a[i]);
                }
                else{
                    last.insert(*last.begin() - 1);
                    ans.insert(*prev(last.end()));
                    last.erase(*prev(last.end()));
                    last.insert(a[i]);
                }
            }
        }
        for(ll val : last){
            ans.insert(val);
        }
    }
    ans.insert(0);
    cout << ans.size() << '\n';
    for(ll val : ans){
        cout << val << (val == *prev(ans.end()) ? '\n' : ' ');
    }

}

int main() {
	int t; cin >> t;
    while(t--){
        solve();
    }
}
