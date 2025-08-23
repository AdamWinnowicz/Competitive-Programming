#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    string names[] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string,int> cows;
    cows["Beatrice"] = 0;
    cows["Belinda"] = 1;
    cows["Bella"] = 2;
    cows["Bessie"] = 3;
    cows["Betsy"] = 4;
    cows["Blue"] = 5;
    cows["Buttercup"] = 6;
    cows["Sue"] = 7;

    vector<int> adj[8];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string cow1,cow2,trash;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;
        adj[cows[cow1]].push_back(cows[cow2]);
        adj[cows[cow2]].push_back(cows[cow1]);
    }

    vector<string> order;

    for(int i = 0; i < 8; i++){
        vector<int> nextTo = adj[i];
        if(nextTo.size() < 2 && order.size() < 8 && find(order.begin(),order.end(),names[i]) == order.end()){
            order.push_back(names[i]);
        }
        if(nextTo.size() == 1 && order.size() < 8 && find(order.begin(),order.end(),names[nextTo[0]]) == order.end()){
            int prev = i;
            int curr = nextTo[0];
            order.push_back(names[curr]);
            while(true){
                vector<int> new_adj = adj[curr];
                bool path = false;
                for(int elem : new_adj){
                    if(elem != prev && order.size() < 8){
                        path = true;
                        order.push_back(names[elem]);
                        prev = curr;
                        curr = elem;
                        break;
                    }
                }
                if(!path){
                    break;
                }
            }
        }
    }

    for(string cow : order){
        cout << cow << '\n';
    }

    return 0;
}