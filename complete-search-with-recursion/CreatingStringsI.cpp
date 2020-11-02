#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

int main() {
    string s; cin >> s;
    vector<string> out;
    sort(all(s));
    do {
        out.pb(s);
    } while(next_permutation(all(s)));
    cout << sz(out) << "\n";
    for(int i = 0; i < sz(out); i++){
        cout << out[i] << "\n";
    }
}
