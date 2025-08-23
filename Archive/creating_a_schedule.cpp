#include <bits/stdc++.h>
using namespace std;
#define ll long long

void test_case(){
    int n, m; cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0;
    int p1 = 0, p2 = m-1;
    while(i < n && p1 <= p2){
        int rooml = a[p1], roomr = a[p2];
        vector<int> row_one(6), row_two(6);
        for(int i = 0; i < 6; i+=2){
            row_one[i] = rooml;
            row_two[i] = roomr;
        }
        for(int i = 1; i < 6; i+=2){
            row_one[i] = roomr;
            row_two[i] = rooml;
        }
        for(int j = 0; j < 6; j++){
            cout << row_one[j] << (j == 5 ? "\n" : " ");
        }
        if(i+1 != n){
            for(int j = 0; j < 6; j++){
                cout << row_two[j] << (j == 5 ? "\n" : " ");
            }
        }
        p1++; p2--;
        i += 2;
    }
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