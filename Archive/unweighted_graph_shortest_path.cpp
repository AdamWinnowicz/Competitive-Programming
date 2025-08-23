#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int start, end;
    cin >> start >> end;

    queue<pair<int,int>> q;
    q.push(make_pair(start,0));
    bool in_queue[n+1] = {};

    bool found = false;
    while(!q.empty()){
        pair<int,int> info = q.front();
        int currnode = info.first;
        int distance = info.second;
        q.pop();
        if(currnode == end){
            found = true;
            cout << distance << '\n';
            break;
        }
        for(int neighbor : adj[currnode]){
            if(!in_queue[neighbor]){
                q.push(make_pair(neighbor, distance + 1));
                in_queue[neighbor] = true;
            }
        }
    }

    if(!found){
        cout << -1 << '\n';
    }

    return 0;
}