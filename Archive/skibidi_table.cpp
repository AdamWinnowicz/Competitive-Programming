#include <bits/stdc++.h>
using namespace std;

int convert(char a, char b){
    if(a == '0' && b == '0') return 0;
    if(a == '1' && b == '1') return 1;
    if(a == '1' && b == '0') return 2;
    if(a == '0' && b == '1') return 3;
}

pair<char,char> back(char s){
    if(s == '0') return {'0','0'};
    if(s == '1') return {'1','1'};
    if(s == '2') return {'1','0'};
    if(s == '3') return {'0','1'};
}

string from_decimal(long long n, long long base){
    string ans = "";
    while(n > 0){
        int remainder = n % base;
        n /= base;
        ans = to_string(remainder) + ans;
    }
    return ans;
}

long long to_decimal(string bin, long long base){
    long long ans = 0, val = 1;
    for(int i = bin.length()-1; i > -1; i--){
        ans += (bin[i] - '0') * val;
        val *= base;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        int q; cin >> q;
        for(int i = 0; i < q; i++){
            string which; cin >> which;
            if(which == "->"){
                long long x,y; cin >> x >> y; x--; y--;
                string sx = from_decimal(x, 2), sy = from_decimal(y, 2);
                long long diff = sx.length() - sy.length();
                if(diff > 0){
                    for(int j = 0; j < diff; j++) sy = "0" + sy;
                }
                else if (diff < 0){
                    for(int j = 0; j < abs(diff); j++) sx = "0" + sx;
                }
                long long ans = 0, val = 1;
                for(int j = sx.length()-1; j > -1; j--){
                    ans += convert(sx[j], sy[j]) * val;
                    val *= 4;
                }
                cout << ans + 1 << '\n';
            }
            else{
                long long d; cin >> d;
                d--;
                string base_four = from_decimal(d, 4);
                string sr = "", sc = "";
                for(int j = 0; j < base_four.length(); j++){
                    pair<char,char> info = back(base_four[j]);
                    sr += info.first; sc += info.second;
                }
                long long r = to_decimal(sr, 2), c = to_decimal(sc, 2);
                cout << r+1 << " " << c+1 << '\n';
            }
        }
    }

    return 0;
}