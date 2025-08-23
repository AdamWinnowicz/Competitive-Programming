#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, x;
    cin >> n >> k >> x;

    priority_queue<pair<int,int>> pq;

    for (int i = 0; i < n; i++){
        int val;
        cin >> val;
        if (pq.size() < k){
            pq.emplace(abs(x-val), val);
        }
        else{
            int currdist = abs(x-val);
            pair<int,int> p = pq.top();
            if (currdist < p.first || (currdist == p.first && val < p.second)){
                pq.pop();
                pq.push(make_pair(abs(x-val), val));
            }
        }
    }

    vector<int> elements;

    while (!pq.empty()){
        pair<int,int> p = pq.top();
        elements.push_back(p.second);
        pq.pop();
    }
    sort(elements.begin(), elements.end());

    for (int i = 0; i < k; i++){
        cout << elements[i] << (i < k - 1 ? " " : "\n");
    }

    return 0;
}