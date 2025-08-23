#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll max_subarray_sum(vector<ll>& a, int start, int end){
    ll mx = a[start], currsum = 0;
    for(int i = start; i < end; i++){
        if(currsum + a[i] > a[i]) currsum += a[i];
        else currsum = a[i];
        mx = max(mx, currsum);
    }
    return mx;
}

void test_case(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<ll> a(n);
    vector<int> unknown = {-1};
    ll MIN = -1e18;
    ll m_max = MIN;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') unknown.push_back(i);
        cin >> a[i];
    }
    unknown.push_back(n);
    if(unknown.size() == 2){
        ll mx = max_subarray_sum(a, 0, n);
        if(mx == k){
            cout << "YES\n";
            for(int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? "\n" : " ");
        }
        else{
            cout << "NO\n";
        }
        return;
    }
    for(int i = 0; i < unknown.size()-1; i++){
        int start = unknown[i], end = unknown[i+1];
        if(start+1 < end){
            ll mx = max_subarray_sum(a, start+1, end);
            m_max = max(m_max, mx);
        }
    }
    if(k >= m_max){
        for(int i = 2; i < unknown.size(); i++){
            if(unknown[i] != n){
                a[unknown[i]] = MIN;
            }
        }
        int start = 0, end = unknown[2];
        ll l = MIN, r = 1e18;
        while(l < r){
            ll m = l + (r - l) / 2;
            a[unknown[1]] = m;
            ll mx = max_subarray_sum(a, start, end);
            if(mx == k) break;
            if(mx < k){
                l = m + 1;
            }
            else{
                r = m;
            }
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? "\n" : " ");
    }
    else{
        cout << "NO\n";
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