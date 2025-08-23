#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool test_case(){
    int n; cin >> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    map<int, int> odd_count, even_count;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0) even_count[b[i]]++;
        else odd_count[b[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            if(even_count[a[i]] > 0) even_count[a[i]]--;
            else return false;
        }
        else{
            if(odd_count[a[i]] > 0) odd_count[a[i]]--;
            else return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        cout << (test_case() ? "Yes\n" : "No\n");
    }

    return 0;
}