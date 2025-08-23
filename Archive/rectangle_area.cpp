#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<double> xVals;
        vector<double> yVals;
        for(int j = 0; j < n; j++){
            double x, y;
            cin >> x >> y;
            xVals.push_back(x);
            yVals.push_back(y);
        }
        double area = ((*max_element(xVals.begin(),xVals.end())-*min_element(xVals.begin(),xVals.end())) * 
        (*max_element(yVals.begin(),yVals.end())-*min_element(yVals.begin(),yVals.end())));
        cout << area << '\n';
    }
    return 0;
}