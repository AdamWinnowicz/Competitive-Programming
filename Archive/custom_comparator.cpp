#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> a = {-15, 7, 3, -2, -7, 9, 4};

    auto cmp = [](int a, int b){
        return abs(a) < abs(b);
    };

    sort(a.begin(), a.end(), cmp);

    for(int i = 0; i < a.size(); i++){
        cout << a[i] << (i == a.size()-1 ? "\n" : " ");
    }

    set<int, decltype(cmp)> s(cmp);
    s.insert(15092352);
    s.insert(-25092);
    s.insert(2309452);
    s.insert(25092);
    s.insert(-25092000);
    
    for(int val : s){
        cout << val << (s.find(val) == prev(s.end()) ? "\n" : " ");
    }

    return 0;
}