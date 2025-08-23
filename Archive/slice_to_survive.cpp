#include <bits/stdc++.h>
using namespace std;

int ops(int l, int w){
    return ceil(log2(l)) + ceil(log2(w));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n,m,a,b; cin >> n >> m >> a >> b;
        vector<int> op;
        op.push_back(ops(a,m)); op.push_back(ops(n,b)); op.push_back(ops(n-a+1,m)); op.push_back(ops(n,m-b+1));
        cout << *min_element(op.begin(),op.end()) + 1 << '\n';
    }
    return 0;
}