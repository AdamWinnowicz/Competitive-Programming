#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int x = 0; x < t; x++){
        string s;
        cin >> s;
        long long u_beforelastw = 0, u_afterlastw = 0, pairs = 0;
        for(char c : s){
            if(c == 'u'){
                u_afterlastw ++;
                pairs += u_beforelastw;
            }
            else if(c == 'w'){
                u_beforelastw += u_afterlastw;
                u_afterlastw = 0;
            }
        }
        cout << pairs << '\n';
    }

    return 0;
}