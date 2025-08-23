#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    int r, p, s; cin >> r >> p >> s;
    string a; cin >> a;
    string b(n, '0');
    int wins = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 'R'){
            if(p > 0){
                wins++; p--; b[i] = 'P';
            } 
        }
        else if(a[i] == 'S'){
            if(r > 0){
                wins++; r--; b[i] = 'R';
            } 
        }
        else{
            if(s > 0){
                wins++; s--; b[i] = 'S';
            } 
        }
    }
    for(int i = 0; i < n; i++){
        if(b[i] == '0'){
            if(r > 0){
                b[i] = 'R'; r--;
            }
            else if(s > 0){
                b[i] = 'S'; s--;
            }
            else if(p > 0){
                b[i] = 'P'; p--;
            }
        }
    }
    if(wins >= (n+1) / 2){
        cout << "YES\n";
        cout << b << '\n';
    }
    else cout << "NO\n";

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