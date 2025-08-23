#include <bits/stdc++.h>
using namespace std;
#define ll long long

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void test_case(){
    string s; cin >> s;
    ll pos; cin >> pos; pos--;
    int n = s.length();
    int curr_len = n;
    vector<char> st;
    for(int i = 0; i < n; i++){
        if(st.empty() || s[i] >= st.back()){
            st.push_back(s[i]);
        }
        else{
            while(pos >= curr_len && !st.empty() && s[i] < st.back()){
                st.pop_back();
                pos -= curr_len;
                curr_len--;
            }
            st.push_back(s[i]);
        }
    }
    while(pos >= curr_len && !st.empty()){
        st.pop_back();
        pos -= curr_len;
        curr_len--;
    }
    cout << st[pos];
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