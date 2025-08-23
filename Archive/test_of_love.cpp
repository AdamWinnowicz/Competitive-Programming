#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int i = -1;
    if(m >= n+1) return true;
    while(i < n+1){
        int furthest_log = i, furthest_water = i;
        if(i + m >= n) return true;
        for(int j = i+1; j <= i + m; j++){
            if(s[j] == 'L'){
                furthest_log = j;
            }
            else if(s[j] == 'W'){
                furthest_water = j;
            }
        }
        if(furthest_log == i){
            if(furthest_water == i || k == 0) return false;
            i = furthest_water; k--;
            while(i+1 < n && s[i+1] == 'W'){
                i++; k--;
            }
            if(k < 0) return false;
            if(i == n-1) return true;
            if(s[i+1] == 'C') return false;
            else i++;
        }
        else{
            i = furthest_log;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}