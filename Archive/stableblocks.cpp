#include <bits/stdc++.h>
using namespace std;

int mass(tuple<int,int,int,int> b){
    int x0 = get<0>(b), y0 = get<1>(b), x1 = get<2>(b), y1 = get<3>(b);
    return (x1 - x0) * (y1 - y0);
}
double center_of_mass(tuple<int,int,int,int> b){
    double x0 = get<0>(b), x1 = get<2>(b);
    return (x1 + x0) / 2.0;
}
pair<double,double> add_up(int i, const vector<tuple<int,int,int,int>>& blocks){
    if(i >= blocks.size()){
        return {0,0};
    }
    pair<double,double> left_side = add_up(2*i+1,blocks);
    pair<double,double> right_side = add_up(2*i+2,blocks);
    int m = mass(blocks[i]);
    double x = center_of_mass(blocks[i]);
    double total_x_numerator = left_side.first + right_side.first + m * x;
    double total_mass = left_side.second + right_side.second + m;
    return {total_x_numerator, total_mass};
}
double COM_of_substructure(int i, const vector<tuple<int,int,int,int>>& blocks){
    pair<double,double> info = add_up(i, blocks);
    // must check that i is not greater than or equal to n to avoid divide by zero
    return info.first / info.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<tuple<int,int,int,int>> blocks;
        for(int i = 0; i < n; i++){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            blocks.emplace_back(a,b,c,d);
        }
        bool found = false;
        for(int i = 1; i < n; i++){
            // check that the current substructure COM lies
            // within the x values of the parent node ((i - 1) / 2)
            double curr_COM = COM_of_substructure(i,blocks);
            int parent_ind = (i - 1) / 2;
            tuple<int,int,int,int> parent_info = blocks[parent_ind];
            if(get<0>(parent_info) > curr_COM || curr_COM > get<2>(parent_info)){
                cout << "Unstable" << '\n';
                found = true;
                break;
            }
        }
        if(!found){
            cout << "Stable" << '\n';
        }
    }
    return 0;
}