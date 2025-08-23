#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    string s; cin >> s;
    // divisible by 9: sum of digits is divisible by 9
    ll total = 0, two_count = 0, three_count = 0;
    for(int i = 0; i < s.length(); i++){
        total += s[i] - '0';
        if(s[i] == '2') two_count++;
        else if (s[i] == '3') three_count++;
    }
    ll remainder = total % 9;
    bool possible = false;
    for(int used_twos = 0; used_twos < 9; used_twos++){
        if(used_twos <= two_count){
            for(int used_threes = 0; used_threes < 4; used_threes++){
                if(used_threes <= three_count && (remainder + 6 * used_threes + 2 * used_twos) % 9 == 0){
                    possible = true; break;
                }
            }
        }
    }
    cout << (possible ? "YES\n" : "NO\n");
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