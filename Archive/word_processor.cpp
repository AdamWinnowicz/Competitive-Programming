#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    string currline = "";
    int currchars = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int len = s.length();
        if(currchars + len <= k){
            if(currchars == 0){
                currline = s;
                currchars = len;
            }
            else{
                currline += " " + s;
                currchars += len;
            }
        }
        else{
            cout << currline << '\n';
            currline = s;
            currchars = len;
        }
    }
    cout << currline << '\n';
    return 0;
}