#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
  
    int ans;
    int minX = min(min(x1, x2), min(x3, x4));
    int maxX = max(max(x1, x2), max(x3, x4));
    int minY = min(min(y1, y2), min(y3, y4));
    int maxY = max(max(y1, y2), max(y3, y4));
    int distX = abs(minX - maxX);
    int distY = abs(minY - maxY);
    ans = max(distX, distY);

    cout << ans * ans << endl;
    return 0;
}
