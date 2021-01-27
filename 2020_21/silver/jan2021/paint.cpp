#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
#include<cmath>

using namespace std;
typedef long long ll;

int n, q, f[100001][2];
string colors;

int strokes(string s){
    int num = 0; char c;
    for(int i = 90; i > 64; i--){       
        c = i; int sz = s.size(); int ctr = 0;

        for(int i = 0; i < sz; i++){
            if(s[i] != s[i+1]){
                if(s[i] == c){ctr++;}
            }
        }
        num += ctr;

        s.erase(remove(s.begin(), s.end(), c), s.end());
    }
    return num;
}

int main(void){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> n >> q >> colors;

    for(int i = 0; i < q; i++){cin >> f[i][0] >> f[i][1];}

    int ans = 0;
    for(int i = 0; i < q; i++) {
        string bound_x1 = colors.substr(0, f[i][0] - 1);
        string bound_x2 = colors.substr(f[i][1]);

        ans = ((strokes(bound_x1)) + (strokes(bound_x2)));
        cout << ans << endl;
    }

    return 0;
}