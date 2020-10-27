#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

using vi = vector<int>;
typedef long long ll;

int main() {
    int n, x; 
    cin >> n >> x;
    vi a(n);
    map<int, int> vals;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if(vals.count(x - a[i])){
            cout << i + 1 << " " << vals[x - a[i]] << endl;
            return 0;
        }
        vals[a[i]] = i + 1;
    }
    cout << "IMPOSSIBLE" << endl;
}