#include<iostream>
#include<algorithm>
using namespace std;
 
int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, X[8], Y[8], x, y;
    cin >> a >> b;
    cin >> x >> y;

    int ans = abs(a - b);
    ans = min(ans, abs(a - x) + abs(b - y));
    ans = min(ans, abs(a - y) + abs(b - x));

    cout << ans << endl;
    return 0;
}
