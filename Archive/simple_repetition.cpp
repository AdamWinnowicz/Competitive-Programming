#include <bits/stdc++.h>
using namespace std;

bool prime(int x){
    if(x == 1) return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int x, k; cin >> x >> k;
        if(k == 1){
            if(prime(x)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else if(x == 1){
            string num = "";
            for(int i = 0; i < k; i++) num += "1";
            if(prime(stoi(num))){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}