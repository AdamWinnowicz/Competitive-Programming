#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if(val == 1){
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";

    return 0;
}