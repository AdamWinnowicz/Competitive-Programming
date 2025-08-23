#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    string l, r; cin >> l >> r;
    int n = l.length();
    bool smaller = false, big_enough = false;
    int ans = 0;
    int i = 0;
    while(i < n && l[i] - '0' == r[i] - '0'){
        i++;
        ans+=2;
    }
    if(i == n || l[i] - '0' <= r[i] - '0' - 2){
        cout << ans << '\n';
    }
    else{
        // calculate the minimum of choosing l[i] and r[i]
        ans += 1; i++;
        while(l[i] - '0' == 9 && r[i] - '0' == 0){
            ans++; i++;
        }
        if(i == n || l[i] - '0' == 9 || r[i] - '0' == 0){
            cout << ans << '\n';
        }
        else{
            int choose_l = 0, choose_r = 0;
            bool found_l = false, found_r = false;
            for(int k = l[i] - '0' + 1; k < 10; k++){
                if(k != r[i] - '0') found_l = true;
            }
            if(!found_l) choose_l++;
            for(int k = r[i] - '0' - 1; k > -1; k--){
                if(k != l[i] - '0') found_r = true;
            }
            if(!found_r) choose_r++;
            ans += min(choose_l, choose_r);
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
        //cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}