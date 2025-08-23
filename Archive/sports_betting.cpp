#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n; cin >> n;
    vector<int> a(n);

    map<int,int> count;
    set<int> seen;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        count[a[i]]++;
        seen.insert(a[i]);
    }

    bool possible = false;
    
    sort(a.begin(), a.end());

    for(int i = 0; i < n-3; i++){
        if(a[i] == a[i+1] && a[i+1] == a[i+2] && a[i+2] == a[i+3]){
            possible = true; break;
        }
    }
    int len = 0, strong = 0, prev = -2;

    for(int val : seen){
        if(val == prev + 1){
            len++;
            if(count[val] >= 2) strong++;
        }
        else{
            if(count[val] >= 2){
                strong = 1; len = 1;
            }
            else len = 0, strong = 0;
        }
        if(strong >= 2){
            possible = true;
            break;
        }
        prev = val;
    }
    
    cout << (possible ? "Yes\n" : "No\n");
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