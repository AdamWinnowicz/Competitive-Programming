#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    string s; cin >> s;
    map<pair<int,int>, int> ratio;
    int d = 0, k = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D') d++;
        else k++;
        int cd = d, ck = k;
        if(d == 0) ck = 1;
        else if(k == 0) cd = 1;
        else{
            int g = __gcd(d, k);
            cd /= g; ck /= g;
        }
        ratio[{cd, ck}]++;
        cout << ratio[{cd, ck}] << (i == n-1 ? "\n" : " ");
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