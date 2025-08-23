#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<int> nums;

    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.insert(num);
    }

    cout << nums.size() << '\n';

    bool first = true;
    for (int element : nums){
        if (!first) {
            cout << " ";
        }
        first = false;
        cout << element;
    }

    return 0;
}