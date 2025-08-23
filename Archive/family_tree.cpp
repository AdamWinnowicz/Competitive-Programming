#include <bits/stdc++.h>
using namespace std;

string parent(string child, map<string,set<string>> &adj){
    for(auto& p : adj){
        if(p.second.count(child)) return p.first;
    }
    return "";
}

int ancestor_dist(const string start, string end, map<string,set<string>> &adj){
    int dist = 0;
    while(end != ""){
        if(start == end) return dist;
        dist++;
        end = parent(end,adj);
    }
    return -1;
}

string relation(string Type, int repetitions){
    if(Type == "mother"){
        if(repetitions == 1) return "mother";
        if(repetitions == 2) return "grand-mother";
        string output = "grand-mother"; repetitions -= 2;
        for(int i = 0; i < repetitions; i++) output = "great-" + output;
        return output;
    }
    else if(Type == "aunt"){
        if(repetitions == 2) return "aunt";
        string output = "aunt"; repetitions -= 2;
        for(int i = 0; i < repetitions; i++) output = "great-" + output;
        return output;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int n;
    string a, b;
    cin >> n >> a >> b;

    map<string,set<string>> adj;
    for(int i = 0; i < n; i++){
        string x, y;
        cin >> x >> y;
        adj[x].insert(y);
    }
    int try1 = ancestor_dist(a,b,adj); int try2 = ancestor_dist(b,a,adj);
    if(try1 != -1) {cout << a << " is the " << relation("mother", try1) << " of " << b << '\n'; return 0;}
    if(try2 != -1) {cout << b << " is the " << relation("mother", try2) << " of " << a << '\n'; return 0;}
    
    string ancestor = parent(b,adj);
    if(ancestor_dist(ancestor,a,adj) == 1){cout << "SIBLINGS\n"; return 0;}
    if(ancestor_dist(ancestor,a,adj) > 1){cout << b << " is the " << relation("aunt", ancestor_dist(ancestor,a,adj)) << " of " << a << '\n'; return 0;}
    ancestor = parent(a,adj);
    if(ancestor_dist(ancestor,b,adj) > 1){cout << a << " is the " << relation("aunt", ancestor_dist(ancestor,b,adj)) << " of " << b << '\n'; return 0;}
    while(ancestor != ""){
        int curr_dist = ancestor_dist(ancestor,b,adj);
        if(curr_dist != -1) {cout << "COUSINS\n"; return 0;}
        ancestor = parent(ancestor,adj);
    }
    cout << "NOT RELATED\n";
    return 0;
}