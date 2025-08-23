#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<bool>& visited, vector<int> adj[]){
    for(int neighbor : adj[i]){
        if(!visited[neighbor]){
            visited[neighbor] = true;
            dfs(neighbor, visited, adj);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<int> adj[N+1];
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(N+1, false);
    int answer = 0;
    for(int i = 1; i < N+1; i++){
        if(!visited[i]){
            answer += 1;
            dfs(i, visited, adj);
        }
    }
    cout << answer << '\n';
    return 0;
}