#include <bits/stdc++.h>
using namespace std;

bool beats(int a, int b, int n){
    if(a == n-1){
        return b != 0;
    }
    if(a == 0){
        return b == n-1;
    }
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool win = false;
        for(int i = 0; i < n; i++){
            if(s[i] == 'A'){
                bool alice = true;
                for(int j = 0; j < n; j++){
                    if(i != j && s[j] == 'B' && !beats(i, j, n)){
                        alice = false; break;
                    }
                }
                if(alice) win = true;
            }
        }
        if(win){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
        
    }

    return 0;
}