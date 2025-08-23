#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    int steps = 0;
    steps += x / 5;
    x %= 5;
    steps += x / 4;
    x %= 4;
    steps += x / 3;
    x %= 3;
    steps += x / 2;
    x %= 2;
    steps += x / 1;
    x %= 1;

    cout << steps << '\n';

    return 0;
}