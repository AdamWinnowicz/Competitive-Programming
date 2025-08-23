#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_set<int> s;

    bool isDuplicate = false;

    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if (s.find(val) != s.end()){
            isDuplicate = true;
            break;
        }
        s.insert(val);
    }

    if (isDuplicate){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}